aux_source_directory(. DIR_LIB_SRCS)

# 将DIR_LIB_SRCS下面的源文件生成库，STATIC 静态库， SHARED 动态库
add_library(Mylib STATIC ${DIR_LIB_SRCS})