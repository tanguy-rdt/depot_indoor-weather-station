cmake_minimum_required(VERSION 3.20)

project(iws VERSION 1.0
            DESCRIPTION "Indoor Weather Station"
            LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(ROOT_DIR         "${CMAKE_SOURCE_DIR}")
set(THIRD_PARTY_DIR  "${ROOT_DIR}/third-party")
set(CONFIG_DIR       "${ROOT_DIR}/config")
set(CMAKE_DIR        "${ROOT_DIR}/cmake")

option(IWS_SIMU "IWS simulator target" OFF)
option(IWS_MINIMAL   "IWS minimal (zephyr) target" OFF)

if(IWS_SIMU)
    include(${CMAKE_DIR}/iws_simu.cmake)
elseif(IWS_MINIMAL)
    include(${CMAKE_DIR}/iws_minimal.cmake)
else()
    message(FATAL_ERROR "No valid target specified. Use -DIWS_SIMU or -DIWS_MINIMAL")
endif()

# BUILD PATH
message(STATUS "BUILD_DIR: ${CMAKE_BINARY_DIR}")