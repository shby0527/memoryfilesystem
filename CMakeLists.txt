cmake_minimum_required(VERSION 3.16)
project(memfs)

set(MEMFS_VERSION "\"V1.0\"")
set(FUSE_USE_VERSION 31)
set(_FILE_OFFSET_BITS 64)
set(CMAKE_BUILD_TYPE "DEBUG")
set(CMAKE_C_FLAGS_DEBUG "-g")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake" ${CMAKE_MODULE_PATH})

find_package(FUSE REQUIRED)

include_directories(${FUSE_INCLUDE_DIRS})

find_package(PTHREAD REQUIRED)

include_directories(${PTHREAD_INCLUDE_DIRS})

CONFIGURE_FILE (
        "${PROJECT_SOURCE_DIR}/config.h.in"
        "${PROJECT_SOURCE_DIR}/config.h")

aux_source_directory(. DIR_SRCS)

add_executable(memfs ${DIR_SRCS})