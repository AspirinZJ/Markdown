# 向工程添加特定的头文件搜索路径，路径之间用空格分隔
include_directories(${PROJECT_SOURCE_DIR}/mylib)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

aux_source_directory(./ DIR_SRCS)

add_executable(demo4 ${DIR_SRCS})

target_link_libraries(demo4 power)
