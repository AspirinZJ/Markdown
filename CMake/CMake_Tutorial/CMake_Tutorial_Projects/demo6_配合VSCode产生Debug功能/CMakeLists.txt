cmake_minimum_required(VERSION 3.10)

project(demo6)

# 下面四行用于VS Code 中调试
add_definitions(-std=c++14)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

add_subdirectory(./mylib)

add_subdirectory(./src)

