cmake_minimum_required(VERSION 3.17)
project(017_Sobel)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV 3.2 REQUIRED)

add_executable(017_Sobel main.cpp)

target_link_libraries(017_Sobel ${OpenCV_LIBS})