cmake_minimum_required(VERSION 3.17)
project(010___)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV 3.2 REQUIRED)

add_executable(010___ main.cpp)

target_link_libraries(010___ ${OpenCV_LIBS})