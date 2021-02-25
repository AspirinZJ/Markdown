cmake_minimum_required(VERSION 3.10)

project(demo3)

# 向当前工程添加存放源文件的子目录，并可以指定中间二进制和目标二进制的存放位置
add_subdirectory(./mylib)

aux_source_directory(./ DIR_SRCS) # ${DIR_SRCS}是.//demo.cpp

add_executable(demo3 ${DIR_SRCS})

target_link_libraries(demo3 Mylib)
