cmake_minimum_required(VERSION 3.17)
project(018_Laplace)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV 3.2 REQUIRED)

add_executable(018_Laplace main.cpp)

target_link_libraries(018_Laplace ${OpenCV_LIBS})