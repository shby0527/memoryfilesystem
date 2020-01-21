cmake_minimum_required(VERSION 3.16)
project(memfs VERSION 1.0.0 LANGUAGES C)

unset(CMAKE_CXX_COMPILER)

set(MEMFS_VERSION "\"V1.0\"")
set(FUSE_USE_VERSION 31)
set(_FILE_OFFSET_BITS 64)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)

find_package(FUSE3 REQUIRED)

include_directories(${FUSE3_INCLUDE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/src/includes)

set(MEMFS_LINK_LIBRARY
    FUSE3::FUSE3
)

CONFIGURE_FILE (
        "${PROJECT_SOURCE_DIR}/src/config.h.in"
        "${PROJECT_SOURCE_DIR}/src/config.h")

aux_source_directory(src DIR_SRCS)
aux_source_directory(src/btree BTREE_SRCS)
list(APPEND DIR_SRCS ${BTREE_SRCS})

add_executable(memfs ${DIR_SRCS})

target_compile_options(memfs PRIVATE -Wall -Wextra)
target_compile_features(memfs PRIVATE ${COMPILE_FEATURES})
target_link_libraries(memfs PRIVATE ${MEMFS_LINK_LIBRARY})