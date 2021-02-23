# 1. 学习背景

C语言工程使用make来构建工程，但是对于大型工程来说文件的依赖关系很复杂，手写makefile非常麻烦，一般开源代码的构建方式都是使用autotool来配置编译环境和自动生成makefile，但是autotool配置涉及到的文件很多，操作步骤比较繁琐，产生了一些替代的方案，cmake是其中最优秀的之一。

cmake相较于autotool简化了很多步骤，只需编写CMakeLists.txt文件，然后运行cmake命令即可。

其实搭建一个非跨平台的工程，我更喜欢eclipse自带的自动构建方式，不用编写什么配置文件，只要在设置里添加头文件路径和库路径，添加文件直接把源文件拷到工程目录下就可以了，因为eclipse里工程目录和文件目录是保持同步的。但是涉及到跨平台的工程，所用到源代码是不同的，对应gcc有不同的编译选项，这时eclipse的灵活性就不够了，需要重新搭建工程。而用自动构建工具的配置文件和脚本结合在一起可以灵活的把不同平台下的编译环境组织到一个工程里面，在makefile里根据需要的平台提供了自定义的多种目标构建方式。

开源代码的编译环境都已经构建好了，不再需要我们重新编写配置文件，运行一条./configure或cmake命令即可，这时会生成一个makefile文件，然后就可以在eclipse指定外部的makefile进行编译了。

虽然开源代码不再需要我们自己写配置文件，但是会看懂配置文件还是十分有必要的，而makefile也需要懂一点，如果一点都不懂的话想添加个源文件或库都不知道从何下手。

以前的老项目都是使用autotool，而cmake出来的晚，使用cmake的项目没有autotool多，但是越来越多的大型项目开始使用cmake构建工程，这应该是一个趋势。

# 2. 使用方法

## 2.1工程目录

首先要安装cmake，在ubuntu下一句话搞定：

`apt-get install cmake`

接下来就以一个实际的小工程为例，来讲解怎么一步步编写CMakeLists.txt文件，工程的目录如下：

```css
bplustree:.
│  CMakeLists.txt
│  coverage_build.sh
│  demo_build.sh
│  LICENSE
│  package.json
│  README.md
│
├─cmake
│      CodeCoverage.cmake
│
├─lib
│      bplustree.c
│      bplustree.h
│      CMakeLists.txt
│
└─tests
        bplustree_coverage.c
        bplustree_demo.c
        CMakeLists.txt
        testcase_generator.py
```

bplustree是一个主目录，在子目录lib和tests里含有源文件，我们需要在这3个目录下分别编写CMakeLists.txt文件。

下面先来看主目录的CMakeLists.txt文件，开头用project来定义项目名称，一般和主目录名保持一致。

```python
cmake_minimum_required (VERSION 2.6)
#定义项目名称
project (bplustree)
#设置debug模式，如果没有这一行将不能调试设断点
set(CMAKE_BUILD_TYPE "Debug")
#设置debug模式下的编译参数
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
#配置自定义模块路径，这里是bplustree /cmake 
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
#配置库名
set(LIB_BPLUSTREE_NAME bplustree)
#进入子目录下执行 CMakeLists.txt文件
add_subdirectory(lib)
add_subdirectory(tests)
```

下面来分析一下==PROJECT_SOURCE_DIR和PROJECT_BINARY_DIR的区别==，如果在bplustree /build目录下执行cmake ..命令,那么==PROJECT_BINARY_DIR指的的是bplustree /build目录，即执行cmake的当前目录==，而==PROJECT_SOURCE_DIR指的的是cmake执行的目录==，这里是上一级目录bplustree。

## 2.2构建动态库和静态库

在lib目录下，通过编译bplustree.c文件生成动态库和静态库，cmake代码如下：

```python
# LIB_BPLUSTREE_SRC是当前目录下的源代码文件集合
set(LIB_BPLUSTREE_SRC bplustree.c)
#这是最后库文件的输出目录，这里是bplustree /build/lib
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
#添加编译选项的宏定义_BPLUS_TREE_DEBUG
add_definitions(-D_BPLUS_TREE_DEBUG)
#生成一个名为bplustree的动态库，即libbplustree.so
add_library(${LIB_BPLUSTREE_NAME} SHARED ${LIB_BPLUSTREE_SRC})
#构建一个新的target，cmake会删除其他同名的库
#因此如果构建libbplustree.a，则会删除libbplustree.so
# CLEAN_DIRECT_OUTPUT 1避免了出现这个问题
set_target_properties(${LIB_BPLUSTREE_NAME} PROPERTIES CLEAN_DIRECT_OUTPUT 1)
#构建动态库版本号和api版本号libbplustree.so1.0和libbplustree.so1
set_target_properties(${LIB_BPLUSTREE_NAME} PROPERTIES VERSION 1.0 SOVERSION 1)
#把动态库安装到目录bplustree /build/lib
install(TARGETS ${LIB_BPLUSTREE_NAME} LIBRARY DESTINATION ${LIBRARY_OUTPUT_PATH})
#静态库和动态库的名字不能相同，静态库需要在末尾加上_static
add_library(${LIB_BPLUSTREE_NAME}_static STATIC ${LIB_BPLUSTREE_SRC})
#让静态库输出以libbplustree.a显示而不是libbplustree_static.a
set_target_properties(${LIB_BPLUSTREE_NAME}_static PROPERTIES OUTPUT_NAME "${LIB_BPLUSTREE_NAME}")
set_target_properties(${LIB_BPLUSTREE_NAME}_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)
#把静态库输出到bplustree /build/lib
install(TARGETS ${LIB_BPLUSTREE_NAME}_static ARCHIVE DESTINATION ${LIBRARY_OUTPUT_PATH})




install(TARGETS ${LIB_BPLUSTREE_NAME}_static ARCHIVE DESTINATION ${LIBRARY_OUTPUT_PATH})
```

## 2.3构建目标

最后执行bplustree /test目录下的CMakeLists.txt来构建最终的目标，构建的目标有2种，分别是bplustree_coverage和bplustree_demo，由CMAKE_BUILD_TYPE来决定具体使用哪一种。

```python
#设置构建目标的名字
set(TEST_NAME ${PROJECT_NAME}_test)
set(COVR_NAME ${PROJECT_NAME}_coverage)
set(DEMO_NAME ${PROJECT_NAME}_demo)
#设置目标输出目录，在bplustree /build/bin
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
#设置头文件所在目录bplustree / lib
set(INC_DIR ${PROJECT_SOURCE_DIR}/lib)
include_directories(${INC_DIR})
# 构建coverage目标
if(${CMAKE_BUILD_TYPE} MATCHES "Coverage")
        set(LIB_DIR ../lib)
        #设置构建目标所需的源文件
        set(SRC_LIST ${LIB_DIR}/bplustree.c bplustree_coverage.c)
        #构建可执行文件bplustree_coverage        
        add_executable(${COVR_NAME} ${SRC_LIST})
        #设置gcc的编译选项
        set(CMAKE_C_FLAGS "-O2 -Wall --coverage")
#使用自定义模块CodeCoverage.cmake   
        include(CodeCoverage)
#执行自定义模块里的函数，生成新的目标coverage
#第一个参数是新的目标名，最后编译时要生成coverage目标，
#使用make coverage，无参数的make命令不会生成该目标
#第2个参数是上面生成的可执行文件
#第3个参数是新目标coverage的输出文件
        setup_target_for_coverage(coverage ${COVR_NAME} coverage)
else()
        set(SRC_LIST bplustree_demo.c)
#生成bplustree_demo可执行文件
        add_executable(${DEMO_NAME} ${SRC_LIST})
        set(CMAKE_C_FLAGS "-O2 -Wall -Werror -Wextra")
#将库文件连接到目标，默认的是动态库优先
#如果要链接静态库需要指明实际的文件
# target_link_libraries(${DEMO_NAME} libbplustree.a)
        target_link_libraries(${DEMO_NAME} ${LIB_BPLUSTREE_NAME})
endif()
```

在makefile中的目标(target)，相当于一个个段落标签，从当标签开始执行，到下一个标签结束，如

```cpp
all：
  ……
coverager：
  …….
clean：
  ……
```

上面的例子中，all、coverager和clean就是一个目标，默认make执行的是make all，需要执行其他目标时需要在make后声明参数，如make coverager、make clean，此时将不会执行目标all里的语句。