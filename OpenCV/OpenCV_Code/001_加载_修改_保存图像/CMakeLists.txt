cmake_minimum_required(VERSION 3.17)
project(001___)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV 3.2 REQUIRED)

add_executable(001___ src/main.cpp)

target_link_libraries(001___ ${OpenCV_LIBS})