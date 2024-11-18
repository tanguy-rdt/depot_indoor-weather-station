message(STATUS "Build Indoor Weather Station simulator")

message(STATUS "ROOT_DIR: ${ROOT_DIR}")
message(STATUS "THIRD_PARTY_DIR: ${THIRD_PARTY_DIR}")
message(STATUS "CONFIG_DIR: ${CONFIG_DIR}")


# ADD LVGL THIRD-PARTY
add_subdirectory(${THIRD_PARTY_DIR}/lvgl)

set(LVGL_HEADERS ${THIRD_PARTY_DIR}/lvgl)
set(LV_CONF_PATH ${CONFIG_DIR}/lv_conf.h)
set(LV_BUILD_EXAMPLES OFF)

target_compile_definitions(lvgl PUBLIC LV_CONF_PATH=${LV_CONF_PATH})


# ADD SDL2
if(APPLE)
    find_package(SDL2 REQUIRED)
    include_directories(${SDL2_INCLUDE_DIRS})
else()
    find_package(SDL2 REQUIRED)
endif()


# ADD LV_DRIVERS
add_subdirectory(${THIRD_PARTY_DIR}/lv_drivers)

set(LV_DRIVERS_HEADERS ${THIRD_PARTY_DIR}/lv_drivers)
set(LV_DRV_CONF_PATH   ${CONFIG_DIR})

target_include_directories(lv_drivers BEFORE PUBLIC ${LV_DRV_CONF_PATH})


# ADD .cpp & .h
set(SRC_DIR ${ROOT_DIR}/src)

set(SRC
    ${SRC_DIR}/main.cpp
    ${SRC_DIR}/hal/hal.cpp
    ${SRC_DIR}/hal/hal_stub/hal_stub.cpp
    ${SRC_DIR}/hal/hal_stub/display/display.cpp
)

set(INCLUDE_DIRS
    ${SRC_DIR}
    ${SRC_DIR}/hal
    ${SRC_DIR}/hal/hal_stub
    ${SRC_DIR}/hal/hal_stub/display
)


# LINK
add_executable(iws ${SRC})
target_include_directories(iws PUBLIC ${LVGL_HEADERS} ${INCLUDE_DIRS})
target_link_libraries(iws PRIVATE pthread SDL2::SDL2 lv_drivers lvgl)


# SIMU
option(SIMU "Use simulator mode" ON)
set(SIMU ${SIMU} CACHE INTERNAL "Use simu mode")
target_compile_definitions(iws PUBLIC SIMU=1)


# STUB
option(STUB "Use stub mode" ON)
set(STUB ${STUB} CACHE INTERNAL "Use stub mode")
target_compile_definitions(iws PUBLIC STUB=1)


# BUILD OPT
target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:DEBUG>)
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()