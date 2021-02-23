cmake_minimum_required(VERSION 3.17)
project(20_)

set(CMAKE_CXX_STANDARD 20)

add_executable(20_ src/main.cpp src/identity.cpp src/student.cpp
        src/teacher.cpp src/administrator.cpp src/computerRoom.cpp src/order.cpp)