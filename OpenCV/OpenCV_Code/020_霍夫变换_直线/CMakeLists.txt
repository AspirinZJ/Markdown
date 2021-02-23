cmake_minimum_required(VERSION 3.17)
project(020__)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV 3.2 REQUIRED)

add_executable(020__ main.cpp)

target_link_libraries(020__ ${OpenCV_LIBS})