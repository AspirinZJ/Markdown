cmake_minimum_required(VERSION 3.17)
project(004_)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV 3.2 REQUIRED)

add_executable(004_ main.cpp)

target_link_libraries(004_ ${OpenCV_LIBS})