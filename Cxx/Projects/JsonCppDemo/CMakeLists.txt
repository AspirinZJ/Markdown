cmake_minimum_required(VERSION 3.17)
project(JsonCppDemo)

set(CMAKE_CXX_STANDARD 14)

# 设置jsoncpp路径
set(Jsoncpp_INCLUDE_PATH "/usr/include/jsoncpp")
set(Jsoncpp_LIBRARY "/usr/lib/x86_64-linux-gnu/libjsoncpp.so")

include_directories(${Jsoncpp_INCLUDE_PATH})

add_executable(JsonCppDemo main.cpp)
target_link_libraries(JsonCppDemo ${Jsoncpp_LIBRARY})