message(STATUS "Build Indoor Weather Station minimal")

message(STATUS "ROOT_DIR: ${ROOT_DIR}")
message(STATUS "THIRD_PARTY_DIR: ${THIRD_PARTY_DIR}")
message(STATUS "CONFIG_DIR: ${CONFIG_DIR}")

set(BOARD nucleo_wb55rg)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
set(ZEPHYR "ZEPHYR" CACHE INTERNAL "")


# ZEPHYR
option(SIMU "Use simulator mode" ON)
set(SIMU ${SIMU} CACHE INTERNAL "Use simu mode")


# ADD .cpp & .h
set(SRC_DIR ${ROOT_DIR}/src)

set(SRC
    ${SRC_DIR}/main.cpp
)

set(INCLUDE_DIRS
    ${SRC_DIR}
)


# BUILD PATH
set(EXECUTABLE_OUTPUT_PATH ${BUILD_DIR}/iws_minimal)
message(STATUS "BUILD_DIR: ${BUILD_DIR}/iws_minimal")


# LINK
target_sources(app PRIVATE ${SRC})
target_include_directories(app PRIVATE ${INCLUDE_DIRS})