set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# 提供一个选项
option(USE_MYMATH ON)

# 设置USE_MYMATH选项为ON
# set(USE_MYMATH OFF)

# configure_file(<input> <output>)
# 将input文件里的内容全部复制到output文件之中
# 根据参数规则，替换@VAR@或$VAR$变量
configure_file(
        "${PROJECT_SOURCE_DIR}/config/config.hpp.in"
        "${PROJECT_SOURCE_DIR}/config/config.hpp"
)

IF (USE_MYMATH)
    include_directories(${PROJECT_SOURCE_DIR}/mylib)
ENDIF ()

aux_source_directory(./ DIR_SRCS)

add_executable(demo6 ${DIR_SRCS})

target_link_libraries(demo6 Mylib)
