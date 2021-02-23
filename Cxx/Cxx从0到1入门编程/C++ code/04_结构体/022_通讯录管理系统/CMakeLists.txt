cmake_minimum_required(VERSION 3.3)

project(contactSystem)

set(CMAKE_BUILD_TYPE "Debug")

set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

set(SRC_LIST contactSystem.cxx)

set(DEMO_NAME ${PROJECT_NAME}_demo)
add_executable(${DEMO_NAME} ${SRC_LIST})
