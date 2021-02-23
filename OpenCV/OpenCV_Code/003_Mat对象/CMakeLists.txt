cmake_minimum_required(VERSION 3.17)
project(003_Mat)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV 3.2 REQUIRED)


add_executable(003_Mat src/main.cpp)

target_link_libraries(003_Mat ${OpenCV_LIBS})