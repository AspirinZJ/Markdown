cmake_minimum_required(VERSION 3.10)

project(demo2 CXX)

# 方式1
# add_executable(demo2 main.cpp mymath.cpp)


# 方式2

# 发现一个目录下所有的源代码文件并将列表存储在一个变量中
# 把当前目录下的所有源码文件名赋给变量DIR_SRCS
aux_source_directory("./" DIR_SRCS)

add_executable(demo2  ${DIR_SRCS})
