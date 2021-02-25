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

# ccmake

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