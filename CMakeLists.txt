cmake_minimum_required(VERSION 3.17)
project(webgate C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_VERBOSE_MAKEFILE ON)

add_executable(webgate webgate.c)
add_executable(test test.c)
target_link_libraries(test check)