cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

project(predictivebuffer VERSION 2.1.0)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)
add_library(${PROJECT_NAME} SHARED ${SOURCES})

if (NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "Unable to find Geode SDK! Please define GEODE_SDK environment variable to point to Geode")
else()
    message(STATUS "Found Geode: $ENV{GEODE_SDK}")
endif()

add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)

# Android (and the Apple platforms) build with clang, which is also stricter
# about some MSVC-isms. Nothing platform specific should live outside
# GEODE_IS_WINDOWS guards, but keep the target self contained anyway.
if (GEODE_TARGET_PLATFORM STREQUAL "Android64" OR GEODE_TARGET_PLATFORM STREQUAL "Android32")
    target_compile_definitions(${PROJECT_NAME} PRIVATE PBUF_ANDROID=1)
endif()

setup_geode_mod(${PROJECT_NAME})
