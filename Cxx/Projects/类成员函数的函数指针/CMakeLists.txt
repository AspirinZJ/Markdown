cmake_minimum_required(VERSION 3.17)
project(ClassMemberFunctionPointer)

set(CMAKE_CXX_STANDARD 20)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
add_executable(demo1 src/classMemberFunctionPointer.cpp)
add_executable(demo2 src/一个类中定义一个函数指针绑定另一个类的成员函数.cpp)
add_executable(simpleExamples src/simpleExamples.cpp)
add_executable(demo3 src/指向成员函数的指针的长度_多继承与虚继承对指向成员函数的函数指针的影响.cpp)