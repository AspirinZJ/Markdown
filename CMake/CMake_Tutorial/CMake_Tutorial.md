# CMake中的预定义变量

* PROJECT_SOURCE_DIR 工程根目录
* PROJECT_BINARY_DIR 运行cmake命令的目录 ，通常是${PROJECT_SOURCE_DIR}/build
* CMAKE_INCLUDE_PATH 环境变量，非cmake变量
* CMAKE_LIBRARY_PATH 环境变量
* CMAKE_CURRENT_SOURCE_DIR 当前处理的CMakeLists.txt所在路径
* CMAKE_CURRENT_BINARY_DIR target编译目录，使用add_subdirectory(src bin)可以更改此变量的值， set(EXECUTABLE_OUTPUT_PATH 新路径)并不会改变此变量的值，只是改变了最终目标文件的存储路径
* CMAKE_CURRENT_LIST_FILE 输出调用这个变量的CMakeLists.txt的完整路径
* CMAKE_CURRENT_LIST_LINE 输出这个变量所在的行
* CMAKE_MODULE_PATH 定义自己的cmake模块所在的路径，set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)， 然后可以用INCLUDE命令来调用自己的模块
* EXECUTABLE_OUTPUT_PATH 重新定义目标二进制可执行文件的存放位置
* LIBRARY_OUTPUT_PATH 重新定义目标链接库文件的存放位置
* PROJECT_NAME 通过project指令指定的项目名称
* CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTORS 用来控制IF ELSE语句的书写方式

## 系统信息

- CMAKE_MAJOR_VERSION cmake主版本号
- CMAKE_MINOR_VERSION cmake次版本号
- CMAKE_SYSTEM 系统名称，如Linux-2.6.22
- CMAKE_SYSTEM_NAME 不包含版本的系统名， 如Linux
- CMAKE_SYSTEM_VERSION 系统版本，如2.6.22
- CMAKE_SYSTEM_PROCESSOR 处理器名称，如i686
- UNIX 在所有的类Unix平台为TRUE
- WIN32 在所有的win32平台为TRUE

## 开关选项

* BUILD_SHARED_LIBS 控制默认的库编译方式。如果未设置，使用ADD_LIBRARY时又没有指定库类型，默认编译生成静态库
* CMAKE_C_FLAGS 设置C编译选项
* CMAKE_CXX_FLAGS 设置C++编译选项

# CMake常用命令

## 基本语法规则

* cmake变量使用`${}`方式取值，但是在IF控制语句中是直接使用变量名

* 环境变量使用`$ENV{}`方式取值，使用`SET(ENV{VAR} VALUE)`赋值

* `指令(参数1 参数2 ...)`参数使用 括号括起，参数之间使用空格或分号分开

* ```cmake
  以ADD_EXECUTABLE指令为例：
  ADD_EXECUTABLE(hello main.c func.c)或者
  ADD_EXECUTABLE(hello main.c;func.c)
  ```

## 常用命令列表

### project

`project(项目名 [CXX] [C] [Java])`指定工程名称，并可指定工程支持的语言(可忽略)

### set

`set(VAR [VALUE] [CACHE TYPE DOCSTRING [FORCE]])`定义变量值，可以定义多个VALUE，如`set(SRC_LIST main.c util.c)`

### message

`message([SEND_ERROR | STATUS | FATAL_ERROR] "message to display")` 向终端输出用户定义的信息或变量的值

SEND_ERROR：产生错误，生成过程被跳过

STATUS：输出前缀为--的信息

FATAL_ERROR：立即终止所有cmake进程

### add_executable

`add_executable(可执行程序名 ${SRC_LIST})` 生成可执行文件

### add_library

`add_library(库名称 [SHARED | STATIC | MODULE] [EXCLUDE_FROM_ALL] ${SRC_LIST})` 生成动态库或静态库

SHARED：动态库

STATIC：静态库

MODULE：在使用dyld的系统有效，否则等同于SHARED

EXCLUDE_FROM_ALL：该库不会被默认构建

### set_target_properties

设置输出的名称，设置动态库的版本和API版本

### cmake_minimum_required

`cmake_minimum_required(VERSION 版本号 [FATAL_ERROR])` 声明CMake的版本要求

### add_subdirectory

`add_subdirectory(子路径 [binary_dir] [EXCLUDE_FROM_ALL])` 向当前工程添加存放源文件的子目录，并可以指定中间二进制和目标二进制的存放位置

EXCLUDE_FROM_ALL：将这个目录从编译过程中排除

### include_directories

`include_directories([AFTER | BEFORE] [SYSTEM] 头文件目录1 头文件目录2 ...)`向工程添加多个特定的头文件搜索路径，路径之间用空格分隔，如果路径包含空格，用双引号包含，默认行为为追加到当前头文件搜索路径后面。有如下两种方式指定搜索路径的添加位置：

1. CAMEK_INCLUDE_DIRECTORIES_BEFORE：通过set这个变量为ON,可以将添加的头文件搜索路径添加到已有路径之前
2. 通过AFTER或BEFORE参数控制

### link_directories

`link_directories(路径1 路径2...)`添加非标准的共享库搜索路径

```cmake
cmake_minimum_required(VERSION 2.8.9)
project (TestLibrary)

#For the shared library:
set ( PROJECT_LINK_LIBS libtestStudent.so )
link_directories( ~/exploringBB/extras/cmake/studentlib_shared/build )

#For the static library:
#set ( PROJECT_LINK_LIBS libtestStudent.a )
#link_directories( ~/exploringBB/extras/cmake/studentlib_static/build )

include_directories(~/exploringBB/extras/cmake/studentlib_shared/include)

add_executable(libtest libtest.cpp)
target_link_libraries(libtest ${PROJECT_LINK_LIBS} )
```

### target_link_libraries

`target_link_libraries(目标名称 库1 库2)` 为target添加需要链接的共享库

### add_definitions

`add_definitions(-DENABLE_DEBUG -DABC)`向C/C++添加-D定义，参数之间用空格分隔

### add_dependencies

`add_dependencies(目标名称 depend-target1 depend-target2 ...)`定义target依赖的其他target，确保target在构建之前，其依赖的target已经构建完毕

### aux_source_directory

`aux_source_directory(目录名 变量名)`发现一个目录下所有的源代码文件并将列表存储在一个变量中

### exec_program

`exec_program(Executable [dir where to run] [ARGS <args>] [OUTPUT_VARIABLE <var>][RETURN_VALUE <value>])`用于在指定目录运行某个程序(默认为当前CMakeLists.txt所在目录)，通过ARGS选项添加参数，通过OUTPUT_VARIABLE和RETURN_VALUE获取输出和返回值，如下：

```cmake
# 在src中运行ls命令,在src/CMakeLists.txt添加
EXEC_PROGRAM(ls ARGS "*.c" OUTPUT_VARIABLE LS_OUTPUT RETURN_VALUE LS_RVALUE)
IF (not LS_RVALUE)
    MESSAGE(STATUS "ls result: " ${LS_OUTPUT}) # 缩进仅为美观,语法无要求
ENDIF(not LS_RVALUE)
```

### include

`include(file [OPTIONAL])`用来载入CMakeLists.txt文件

`include(module [OPTIONAL])`用来载入预定义的cmake模块

OPTIONAL参数的左右是文件不存在也不会产生错误

可以载入一个模块，也可以载入预定义模块(模块会在CMAKE_MODULE_PATH)指定的路径进行搜索

载入的内容将在处理到INCLUDE语句时直接执行

### install

将库或可执行文件安装到指定目录

```cmake
install(TARGETS 库名或可执行文件名 DESTINATION 安装目录)
```

例子：

```bash
jackzhang@Deepin:~/exploringBB/extras/cmake/studentlib_shared$ tree
.
├── CMakeLists.txt
├── include
│   └── Student.h
└── src
    └── Student.cpp

2 directories, 3 files
```

CMakeLists.txt文件内容如下：

```cmake
cmake_minimum_required(VERSION 2.8.9)
project(directory_test)
set(CMAKE_BUILD_TYPE Release)

#Bring the headers, such as Student.h into the project
include_directories(include)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")

#Generate the shared library from the sources
add_library(testStudent SHARED ${SOURCES})

#Set the location for library installation -- i.e., /usr/lib in this case
# not really necessary in this example. Use "sudo make install" to apply
install(TARGETS testStudent DESTINATION /usr/lib)
```



###  file

The `file()` command is used to add the source files to the project. `GLOB` (or `GLOB_RECURSE`) is used to create a list of all of the files that meet the globbing expression (i.e., “**src/\*.cpp**“) and add them to a variable.

例如:

```bash
jackzhang@Deepin:~/exploringBB/extras/cmake/student$ tree
.
├── CMakeLists.txt
├── include
│   └── Student.h
└── src
    ├── mainapp.cpp
    └── Student.cpp

2 directories, 4 files
```

CMakeLists.txt中的内容

```cmake
cmake_minimum_required(VERSION 2.8.9)
project(directory_test)
 
#Bring the headers, such as Student.h into the project
include_directories(include)
 
#Can manually add the sources using the set command as follows:
#set(SOURCES src/mainapp.cpp src/Student.cpp)
 
#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")
 
add_executable(testStudent ${SOURCES})
```

### find_

`find_file(<VAR> name path1 path2 ...)`VAR变量代表找到的文件全路径，包含文件名

`find_library(<VAR> name path1 path2 ...)`VAR变量代表找到的库的全路径，包含库文件名

```cmake
FIND_LIBRARY(libX X11 /usr/lib)
IF (NOT libx)
    MESSAGE(FATAL_ERROR "libX not found")
ENDIF(NOT libX)
```

`find_path(<VAR> name path1 path2 ..)`VAR变量代表包含这个文件的路径.该命令用于给定名字文件所在的路径。一条名为<VAR>的cache条目会被创建，并存储该命令的执行结果。如果在某个路径下发现了该文件，该结果会被存储到该变量中；除非该变量被清除，该次搜索不会继续进行。如果没有找到，存储的结果将会是<VAR>-NOTFOUND，并且当下一次以相同的变量名调用find_path命令时，该命令会再一次尝试搜索该文件。需要搜索的文件名通过在NAMES选项后面的列出来的参数来确定。附加的搜索位置可以在PATHS选项之后指定。如果在PATHS或者HINTS命令中还指定了ENV var选项，环境变量var将会被读取并从一个系统环境变量转换为一个cmake风格的路径list。比如，ENV PATH是列出系统path变量的一种方法。参数DOC将用来作为该变量在cache中的注释。PATH_SUFFIXES指定了在每个搜索路径下的附加子路径。

`find_package(<name> [major.minor] [QUIET] [NO_MODULE] [[REQUIRED | COMPONENTS] [components ...]])`用来调用预定义在CMAKE_MODULE_PATH下的Find<name>.cmake模块，也可以自己定义Find<name>模块，通过set(CMAKE_MODULE_PATH  dir)将其放入工程的某个目录供工程使用

### IF

语法：

```cmake
IF (expression)
    COMMAND1(ARGS ...)
    COMMAND2(ARGS ...)
    ...
ELSE (expression)
    COMMAND1(ARGS ...)
    COMMAND2(ARGS ...)
    ...
ENDIF (expression) # 一定要有ENDIF与IF对应
```

IF (expression), expression不为：空,0,N,NO,OFF,FALSE,NOTFOUND或<var>_NOTFOUND,为真
IF (not exp), 与上面相反
IF (var1 AND var2)
IF (var1 OR var2)
IF (COMMAND cmd) 如果cmd确实是命令并可调用,为真
IF (EXISTS dir) IF (EXISTS file) 如果目录或文件存在,为真
IF (file1 IS_NEWER_THAN file2),当file1比file2新,或file1/file2中有一个不存在时为真,文件名需使用全路径
IF (IS_DIRECTORY dir) 当dir是目录时,为真
IF (DEFINED var) 如果变量被定义,为真
IF (var MATCHES regex) 此处var可以用var名,也可以用${var}
IF (string MATCHES regex)

```cmake
当给定的变量或者字符串能够匹配正则表达式regex时为真。比如：
IF ("hello" MATCHES "ell")
    MESSAGE("true")
ENDIF ("hello" MATCHES "ell")
```

- **数字比较表达式**
  IF (variable LESS number)
  IF (string LESS number)
  IF (variable GREATER number)
  IF (string GREATER number)
  IF (variable EQUAL number)
  IF (string EQUAL number)

  **按照字母表顺序进行比较**
  IF (variable STRLESS string)
  IF (string STRLESS string)
  IF (variable STRGREATER string)
  IF (string STRGREATER string)
  IF (variable STREQUAL string)
  IF (string STREQUAL string)

  ```cmake
  一个小例子,用来判断平台差异：
  IF (WIN32)
      MESSAGE(STATUS “This is windows.”)
  ELSE (WIN32)
      MESSAGE(STATUS “This is not windows”)
  ENDIF (WIN32)
  上述代码用来控制在不同的平台进行不同的控制,但是,阅读起来却并不是那么舒服,ELSE(WIN32)之类的语句很容易引起歧义。
  可以SET(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS ON)
  这时候就可以写成:
  IF (WIN32)
  ELSE ()
  ENDIF ()
  配合ELSEIF使用,可能的写法是这样:
  IF (WIN32)
      #do something related to WIN32
  ELSEIF (UNIX)
      #do something related to UNIX
  ELSEIF(APPLE)
      #do something related to APPLE
  ENDIF (WIN32)
  ```

### WHILE

语法：

```cmake
WHILE(condition)
    COMMAND1(ARGS ...)
    COMMAND2(ARGS ...)
    ...
ENDWHILE(condition)
```

其真假判断条件可以参考IF指令

### FOREACH

FOREACH指令的使用方法有三种形式：

1. 列表

   ```cmake
   FOREACH(loop_var arg1 arg2 ...)
        COMMAND1(ARGS ...)
        COMMAND2(ARGS ...)
    ...
   ENDFOREACH(loop_var)
   ```

   ```cmake
   AUX_SOURCE_DIRECTORY(. SRC_LIST)
   FOREACH(F ${SRC_LIST})
        MESSAGE(${F})
   ENDFOREACH(F)
   ```

2. 范围

   ```cmake
   FOREACH(loop_var RANGE total)
       COMMAND1(ARGS ...)
       COMMAND2(ARGS ...)
       ...
   ENDFOREACH(loop_var)
   ```

   ```cmake
   # 从0到total以１为步进
   FOREACH(VAR RANGE 10)
      MESSAGE(${VAR})
   ENDFOREACH(VAR)
   
   ---
   输出：
   012345678910
   ```

3. 范围和步进

   ```cmake
   FOREACH(loop_var RANGE start stop [step])
       COMMAND1(ARGS ...)
       COMMAND2(ARGS ...)
       ...
   ENDFOREACH(loop_var)
   ```

   **注意：**直到遇到ENDFOREACH指令,整个语句块才会得到真正的执行。

   ```cmake
   FOREACH(A RANGE 5 15 3)
       MESSAGE(${A})
   ENDFOREACH(A)
   ---
   输出：
   581114
   ```

### option

option 提供一个用户可以任选的选项。语法如下

```cmake
option(<option_variable> "help string describing option" [initial value])
```

   option 提供选项让用户选择是 ON 或者 OFF ，如果没有提供初始化值，使用OFF。也就是说默认的值是OFF。但是请注意：这个option命令和你本地是否存在编译缓存的关系很大。所以，如果你有关于 option 的改变，那么、请你务必清理 CMakeCache.txt 和 CMakeFiles 文件夹。还有，请使用标准的 [initial value] 值 ON 或者 OFF。

### list

```cmake
list(LENGTH <list><output variable>)
list(GET <list> <elementindex> [<element index> ...] <output variable>)
list(APPEND <list><element> [<element> ...])
list(FIND <list> <value><output variable>)
list(INSERT <list><element_index> <element> [<element> ...])
list(REMOVE_ITEM <list> <value>[<value> ...])
list(REMOVE_AT <list><index> [<index> ...])
list(REMOVE_DUPLICATES <list>)
list(REVERSE <list>)
list(SORT <list>)
```

LENGTH返回列表的长度
GET返回列表中指定下标的元素
APPEND添加新元素到列表中
INSERT 将新元素插入到列表中指定的位置
REMOVE_ITEM从列表中删除某个元素
REMOVE_AT从列表中删除指定下标的元素
REMOVE_DUPLICATES从列表中删除重复的元素
REVERSE 将列表的内容实地反转，改变的是列表本身，而不是其副本
SORT 将列表按字母顺序实地排序，改变的是列表本身，而不是其副本

### set_property & source_group

对于有编译目标的单元（即有ADD_EXECUTABLE或者ADD_LIBRARY），那么我们通过一下命令可以把这个编译单元放到
某个目录下：

```cmake
SET_PROPERTY(TARGET trivial PROPERTY FOLDER "libraries")  
```

SET_PPRPERTY第一个参数TARGET是固定值,第二个trivial就是编译单元的名称，第三个PROPERTY，第四个FOLDER都是固定值，第五个libiraries是要放到的目录名称。目录支持层级结构，这里用/来划分层级结构，如libraries/cnn。

# gcc编译的流程

gcc的参数：

```bash
-B <directory>           Add <directory> to the compiler's search paths.
-v                       Display the programs invoked by the compiler.
-###                     Like -v but options quoted and commands not executed.
-E                       Preprocess only; do not compile, assemble or link.
-S                       Compile only; do not assemble or link.
-c                       Compile and assemble, but do not link.
-o <file>                Place the output into <file>.
-pie                     Create a dynamically linked position independent executable.
-shared                  Create a shared library.
-x <language>            Specify the language of the following input files.
```

gcc 编译main.c的详细流程：

```bash
gcc -E main.c -o main.i # 预处理，不编译，不汇编，不链接
gcc -S main.i -o main.s	# 只编译，不汇编，不链接
gcc -c main.s -o main.o	# 编译和汇编，不链接
gcc main.o -o main.out	# 链接
```

# CMake用法

## 指定文件输出路径

指定可执行文件输出路径：`set(EXECUTABLE_OUTPUT_PATH 输出路径)`， 如

```cmake
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
```

指定库文件输出路径：`set(LIBRARY_OUTPUT_PATH 输出路径)`，如

```cmake
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
```

上面的两条命令通常紧跟ADD_EXECUTABLE和ADD_LIBRARY,与其写在同一个CMakeLists.txt即可

## 生成动态库和静态库

参考ADD_LIBRARY和SET_TARGET_PROPERTIES用法

示例：

文件结构为：

```bash
├── CMakeLists.txt
└── lib_hello
    ├── CMakeLists.txt
    ├── hello.cpp
    └── hello.h
```

lib_hello/CMakeLists.txt内容为：

```cmake
AUX_SOURCE_DIRECTORY(. SRC_LIST)
ADD_LIBRARY(hello_shared SHARED ${SRC_LIST}) # lib的名字不能重复
ADD_LIBRARY(hello_static STATIC ${SRC_LIST})
SET_TARGET_PROPERTIES(hello_static PROPERTIES OUTPUT_NAME "hello")
SET_TARGET_PROPERTIES(hello_shared PROPERTIES OUTPUT_NAME "hello")

# 设置动态库的版本号
SET_TARGET_PROPERTIES(hello_shared PROPERTIES VERSION 1.2 SOVERSION 1)

# 如果发现后来生成的lib清除了同名的早先生成的lib，（只有一个静态库或动态库生成）
# 试下下面两个命令
# 较新版本的cmake不再需要下面两个命令就可以同时生成hello.so hello.a
#SET_TARGET_PROPERTIES(hello_shared PROPERTIES CLEAN_DIRECT_OUTPUT 1)
#SET_TARGET_PROPERTIES(hello_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
```

CMakeLists.txt内容为：

```cmake
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(T3)
# 若变量BUILD_SHARED_LIBS没有设置，并且在ADD_LIBRARY时没有指定库类型
# 默认生成的都是静态库
#SET(BUILD_SHARED_LIBS on)
ADD_SUBDIRECTORY(lib_hello)
```

## 使用动态库和静态库以及查找库路径

参考INCLUDE_DIRECTORIES, LINK_DIRECTORIES, TARGET_LINK_LIBRARIES用法

### 示例：从其他文件夹使用库

在`/home/carl/cmake/t4`目录下的文件结构如下：

```
├── CMakeLists.txt                                                                                        └── src                                                                                                   	├── CMakeLists.txt   
	└── main.cpp 
```

其中，src/CMakeLists.txt文件的内容如下，main.cpp中需要从其他文件夹调用库

```cmake
AUX_SOURCE_DIRECTORY(. SRC_LIST)
LINK_DIRECTORIES(/home/carl/cmake/t3/build/lib) # 这行一定要在ADD_EXECUTABLE前面
ADD_EXECUTABLE(t4 ${SRC_LIST})
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

SET(CMAKE_PROJECT_DIR /home/carl/cmake) # cmake文件夹的位置
INCLUDE_DIRECTORIES(${CMAKE_PROJECT_DIR}/t3/lib_hello)
TARGET_LINK_LIBRARIES(t4 hello) # 链接动态库
#TARGET_LINK_LIBRARIES(t4 libhello.a) # 链接静态库
```

### 示例：如何使用cmake预定义的cmake模块

有文件结构如下：

```
├── CMakeLists.txt
└── src
    ├── CMakeLists.txt
    └── main.c
```

main.c文件需要使用curl，内容为：

```c
#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

FILE *fp;

int write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    int written = fwrite(ptr, size, nmemb, (FILE *)fp);
    return written;
}


// 通过curl取回www.linux-ren.org的首页并写入/tmp/curl-test文件中
int main()
{
    const char *path = "tmp/curl-test";
    const char *mode = "w";

    fp = fopen(path, mode);
    curl_global_init(CURL_GLOBAL_ALL);
    CURLcode res;
    CURL *curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, "http://www.linux-ren.org");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
    res = curl_easy_perform(curl);

    curl_easy_cleanup(curl);
}
```

其中,src/CMakeLists.txt内容如下：

```cmake
AUX_SOURCE_DIRECTORY(. SRC_LIST)
ADD_EXECUTABLE(curltest ${SRC_LIST})
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
# INCLUDE_DIRECTORIES(/usr/include)
# TARGET_LINK_LIBRARIES(curltest curl)
FIND_PACKAGE(CURL)
IF (CURL_FOUND)
    MESSAGE(STATUS "CURL_INCLUDE_DIR: " ${CURL_INCLUDE_DIR} " CURL_LIBRARY: " ${CURL_LIBRARY})
    INCLUDE_DIRECTORIES(${CURL_INCLUDE_DIR})
    TARGET_LINK_LIBRARIES(curltest ${CURL_LIBRARY})
ELSE(CURL_FOUND)
    MESSAGE(FATAL_ERROR "CURL library not found")
ENDIF(CURL_FOUND)

#对于系统预定义的Find<name>.cmake模块，使用方法一般如上所示：
#每一个模块都会定义以下几个变量
#• <name>_FOUND   通过此变量判断模块是否被找到
#• <name>_INCLUDE_DIR or <name>_INCLUDES
#• <name>_LIBRARY or <name>_LIBRARIES
```

### 示例：使用自定义的cmake模块

文件组织如下：

```
├── cmake
│   └── FindHELLO.cmake
├── CMakeLists.txt
└── src
    ├── CMakeLists.txt
    └── main.cpp
```

在main.cpp中，需要另一个目录下面的hello库，main.cpp内容如下：

```c++
#include <hello.h>

int main()
{
    Hello();
    return 0;
}
```

src/CMakeLists.txt内容如下：

```cmake
AUX_SOURCE_DIRECTORY(. SRC_LIST)
ADD_EXECUTABLE(t6 ${SRC_LIST})
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# 没有指定QUIET参数, HELLO_FIND_QUIETLY为假
# 指定REQUIRED参数, HELLO_FIND_REQUIRED为真, 意味着此lib为该Project必须
FIND_PACKAGE(HELLO REQUIRED) 
# 下面的HELLO_FOUND  HELLO_INCLUDE_DIR  HELLO_LIBRARY
# 3个变量在FindHELLO.cmake中定义
IF (HELLO_FOUND)
    INCLUDE_DIRECTORIES(${HELLO_INCLUDE_DIR})
    TARGET_LINK_LIBRARIES(t6 ${HELLO_LIBRARY})
ENDIF (HELLO_FOUND)
```

cmake/FindHELLO.cmake内容如下

```cmake
# 注意此cmake文件中的3个变量名
# HELLO_INCLUDE_DIR -- <name>_INCLUDE_DIR
# HELLO_LIBRARY     -- <name>_LIBRARY
# HELLO_FOUND       -- <name>_FOUND
# 惯例需要定义这3个变量，命名规则如上，以便与cmake预定义的cmake模块中的变量名统一

# FIND_PATH和FIND_LIBARY的path部分，一定要是.h文件和lib文件所在的当前目录，否则找不到
FIND_PATH(HELLO_INCLUDE_DIR hello.h /home/carl/cmake/t3/lib_hello)
MESSAGE(STATUS "HELLO_INCLUDE_DIR: " ${HELLO_INCLUDE_DIR})

FIND_LIBRARY(HELLO_LIBRARY hello /home/carl/cmake/t3/build/lib)
MESSAGE(STATUS "HELLO_LIBRARY: " ${HELLO_LIBRARY})


IF (HELLO_INCLUDE_DIR AND HELLO_LIBRARY)
    SET(HELLO_FOUND TRUE)
ENDIF(HELLO_INCLUDE_DIR AND HELLO_LIBRARY)

IF (HELLO_FOUND)
    # 若FIND_PACKAGE命令没有指定QUIET参数，那下面的IF语句就为真
    IF (NOT HELLO_FIND_QUIETLY)
        MESSAGE(STATUS "Found Hello: ${HELLO_LIBRARY}")
    ENDIF (NOT HELLO_FIND_QUIETLY)
ELSE (HELLO FOUND)
    # 如果FIND_PACKAGE命令指定了REQUIRED参数，说明这个库是此Project必须的
    # 对应下面的HELLO_FIND_REQUIRED变量
    IF (HELLO_FIND_REQUIRED)
        MESSAGE(FATAL_ERROR "Could not find hello library")
    ENDIF (HELLO_FIND_REQUIRED)
ENDIF (HELLO_FOUND)
```

## cmake中增加编译选项

使用变量CMAKE_C_FLAGS添加C编译选项
使用变量CMAKE_CXX_FLAGS添加C++编译选项
使用ADD_DEFINITION添加

## 增加头文件路径

参考INCLUDE_DIRECTORIES命令用法



## 卸载安装的程序

1. 进入build目录，运行完成make install 之后目录下会生成install_manifest.txt文件
2. 通过`cat install_manifest.txt | sudo xargs rm`或者是`xargs rm < install_manifest.txt`

## ccmake

ccmake是一个类似于图形界面的cmake工具，在运行完`cmake ..`命令之后，可以运行`ccmake .`来进行配置，然后build

安装ccmake：

```bash
sudo apt install cmake-curse-gui
```

# VS Code中使用Cmake调试

1. 在项目最顶层的CMakeLists.txt中添加以下四行

```cmake
# 下面四行用于VS Code 中调试
add_definitions(-std=c++14)	# c++ 14标准用此选项
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall"
```

2. build一下，生成可执行文件
3. 从菜单里面Run->Start Debugging->C++，会生成launch.json文件
4. 将"program"中的可执行文件更改为生成的可执行文件路径, 有时候可能需要将 "console": "externalTerminal", 改为"externalConsole"：false,
5. 之后可以在代码里添加断点，从菜单中的Run->Start Debugging，就能开始调试

# 指令说明

## configure_file 

### 指令说明

```cmake
configure_file(<input> <output>
               [COPYONLY] [ESCAPE_QUOTES] [@ONLY]
               [NEWLINE_STYLE [UNIX|DOS|WIN32|LF|CRLF] ])
```

`configure_file` 主要实现如下两个功能:

1. 将 `<input>` 文件里面的内容全部复制到 `<output>` 文件中；
2. 根据参数规则，替换 `@VAR@` 或 `${VAR}` 变量；

### 参数解析

1. COPYONLY
   - 仅拷贝 `<input>` 文件里面的内容到 `<output>` 文件， **不进行变量的替换**；
2. ESCAPE_QUOTES
   - 使用反斜杠（C语言风格）来进行转义；
3. @ONLY
   - 限制替换， 仅仅替换 `@VAR@` 变量， 不替换 `${VAR}` 变量
4. NEWLINE_STYLE
   - 指定输入文件的新行格式， 例如：Unix 中使用的是 `\n`, windows 中使用的 `\r\n`

**注意: ** `COPYONLY` 和 `NEWLINE_STYLE` 是冲突的，不能同时使用；

### Coding

文件目录结构如下:

```shell
├── CMakeLists.txt
├── Config.h.in
├── make.sh
└── tutorial.cpp
```

**CMakeLists.txt** 文件内容:

```cmake
cmake_minimum_required(VERSION 3.5)

project(Tutorial)

message(STATUS "PROJECT_SOURCE_DIR " ${PROJECT_SOURCE_DIR})
message(STATUS "PROJECT_BINARY_DIR " ${PROJECT_BINARY_DIR})

set(CMAKEDEFINE_VAR1 1)
set(CMAKEDEFINE_VAR2 0)

set(DEFINE_VAR1 1)
set(DEFINE_VAR2 0)


configure_file (
  "${PROJECT_SOURCE_DIR}/Config.h.in"
  "${PROJECT_BINARY_DIR}/Config.h"
  )

include_directories("$PROJECT_SOURCE_DIR")

add_executable(DEMO tutorial.cpp)
```

**Config.h.in** 文件内容

```cmake
/**
 * This is the configure demo  
 *    - CMAKEDEFINE_VAR1 = @CMAKEDEFINE_VAR1@
 *    - CMAKEDEFINE_VAR2 = @CMAKEDEFINE_VAR2@
 *    - DEFINE_VAR1      = @DEFINE_VAR1@
 *    - DEFINE_VAR2      = @DEFINE_VAR2@
 */

/**
 *  cmakedefine 会根据变量的值是否为真（类似 if）来变换为 #define VAR ... 或  #undef VAR 
 */
#cmakedefine CMAKEDEFINE_VAR1 @CMAKEDEFINE_VAR1@
#cmakedefine CMAKEDEFINE_VAR2 @CMAKEDEFINE_VAR2@


/**
 * define 会直接根据规则来替换
 */
#define DEFINE_VAR1 @DEFINE_VAR1@
#define DEFINE_VAR2 ${DEFINE_VAR2}
```

**tutorial.cpp ** 文件内容

```c++
// 计算平方根的简单程序。
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Config.h"

int main (int argc, char *argv[]) {
  
#ifdef CMAKEDEFINE_VAR1
   fprintf(stdout,"CMAKEDEFINE_VAR1 = %d\n", CMAKEDEFINE_VAR1);
#endif 

#ifdef CMAKEDEFINE_VAR2
   fprintf(stdout,"CMAKEDEFINE_VAR2 = %d\n", CMAKEDEFINE_VAR2);
#endif 

#ifdef DEFINE_VAR1
   fprintf(stdout,"DEFINE_VAR1 = %d\n", DEFINE_VAR1);
#endif 

#ifdef DEFINE_VAR2
   fprintf(stdout,"DEFINE_VAR2 = %d\n", DEFINE_VAR2);
#endif 
 
  return 0;
}
```

**make.sh** 保存一些指令(这个非必须)

```shell
#!/bin/sh

# 删除一些产生的文件
rm -rf CMakeFiles
rm cmake_install
rm Makefile
rm Config.h
rm DEMO
rm CMakeCache.txt
rm -rf ./vscode
rm cmake_install.cmake

cmake ./
make

./DEMO
```

运行 `sh make.sh`

生成一个 **Config.h** 配置文件，文件内容为:

```cmake
/**
 * This is the configure demo  
 *    - CMAKEDEFINE_VAR1 = 1
 *    - CMAKEDEFINE_VAR2 = 0
 *    - DEFINE_VAR1      = 1
 *    - DEFINE_VAR2      = 0
 */

/**
 *  cmakedefine 会根据变量的值是否为真（类似 if）来变换为 #define VAR ... 或  #undef VAR 
 */
#define CMAKEDEFINE_VAR1 1
/* #undef CMAKEDEFINE_VAR2 */


/**
 * define 会直接根据规则来替换
 */
#define DEFINE_VAR1 1
#define DEFINE_VAR2 0
```

终端显示：

```shell
.....

Scanning dependencies of target DEMO
[ 50%] Building CXX object CMakeFiles/DEMO.dir/tutorial.cpp.o
[100%] Linking CXX executable DEMO
[100%] Built target DEMO
CMAKEDEFINE_VAR1 = 1
DEFINE_VAR1 = 1
DEFINE_VAR2 = 0
```