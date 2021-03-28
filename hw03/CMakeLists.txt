cmake_minimum_required(VERSION 3.0)
project(cso-hw03)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -std=c99")

set(SOURCE_FILES src/minheap.c src/huffman.c)
add_executable(huffman ${SOURCE_FILES})
