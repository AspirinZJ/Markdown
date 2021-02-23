clion是一个强大的编辑器,之前使用qt时就用Qt Creator,使用clion后就换不回去了,qt的排版看着太别扭,阅读起来有点费劲。
默认已经安装好qt和clion了
打开clion

#### 1.配置QtDesigner

![在这里插入图片描述](pics/ubuntu16.04%E7%8E%AF%E5%A2%83%E4%B8%8Bclion%E9%85%8D%E7%BD%AEqt%E7%8E%AF%E5%A2%83/20190919190138554.jpeg)
**Arguments:** `$FileName$`
**working directory:**`$ProjectFileDir$`
**programe**中的路径为qtcreator的路径，在你qt安装路径下找（也可以使用系统中的`usr/bin/qtcreator`，）
如我用的是

```
/opt/Qt5.9.2/Tools/QtCreator/bin/qtcreator
1
```

#### 2.配置uic

![在这里插入图片描述](pics/ubuntu16.04%E7%8E%AF%E5%A2%83%E4%B8%8Bclion%E9%85%8D%E7%BD%AEqt%E7%8E%AF%E5%A2%83/20190919190515577.jpeg)
**arguments:**`$FileName$ -o ui_$FileNameWithoutExtension$.h`
**working directory:**`$ProjectFileDir$`
**programe**中的路径为uic的路径，在你qt安装路径下找（也可以使用系统中的`usr/bin/uic`，）
如我用的是

```
/opt/Qt5.9.2/5.9.2/gcc_64/bin/uic
1
```

#### 3.使用

**1.CMakeLists**

```cpp
cmake_minimum_required(VERSION 3.10)
project(qt_test)

# 指定c++标准的版本
set(CMAKE_CXX_STANDARD 17)

# 自动调用moc，uic，rcc处理qt的扩展部分
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# 设置Qt5的cmake模块所在目录，如果不设置将使用系统提供的版本
# QT_DIR和QT_VERSION是指定了qt安装目录和版本的环境变量
# 如果你使用了系统的cmake，那么会优先使用系统提供模块，如果不想发生这种行为你需要自己运行cmake或者使用CLion自带的
set(CMAKE_PREFIX_PATH $ENV{QT_DIR}/$ENV{QT_VERSION}/gcc_64/lib/cmake)

# 找到对应的qt模块，名字为qmake中QT += <name>中的name首字母大写后加上Qt5前缀
# 例如core为QtCore，你也可以去${CMAKE_PREFIX_PATH}的目录中找到正确的模块名
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)

aux_source_directory(. DIRS_SRCS)

# 通常这样设置就可以，如果你的项目包含qrc文件，那么需要将它们单独添加进来
# 例如add_executable(test ${DIRS_SRCS} resources.qrc)
add_executable(qt_test ${DIRS_SRCS})

# 把对应Qt模块的库链接进程序
target_link_libraries(qt_test Qt5::Widgets)
12345678910111213141516171819202122232425262728293031
```

**2.创建.ui文件后，右键该文件**
![在这里插入图片描述](pics/ubuntu16.04%E7%8E%AF%E5%A2%83%E4%B8%8Bclion%E9%85%8D%E7%BD%AEqt%E7%8E%AF%E5%A2%83/2019091920565648.jpg)
**3.使用uic工具生成头文件**
![在这里插入图片描述](pics/ubuntu16.04%E7%8E%AF%E5%A2%83%E4%B8%8Bclion%E9%85%8D%E7%BD%AEqt%E7%8E%AF%E5%A2%83/20190919205728718.jpg)