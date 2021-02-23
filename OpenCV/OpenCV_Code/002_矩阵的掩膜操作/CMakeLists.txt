cmake_minimum_required(VERSION 3.17)
project(002_)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV 3.2 REQUIRED)

add_executable(002_ src/main.cpp)

target_link_libraries(002_ ${OpenCV_LIBS})