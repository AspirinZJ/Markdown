cmake_minimum_required(VERSION 3.17)
project(016_)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV 3.2 REQUIRED)

add_executable(016_ main.cpp)

target_link_libraries(016_ ${OpenCV_LIBS})