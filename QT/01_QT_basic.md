# 简介

创建工程时三种基类的区别：

* QWidget：最基础的类， 窗口类
* QMainWindow：继承自QWidget类， 多了菜单栏，工具，状态栏等功能
* QDialog：继承自QWidget类，对话框



main函数：

* `QApplication qapp; // 创建应用程序对象，有且仅有一个`
* `myWidget w; w.show(); // 调用show函数，显示窗口`
* `return qapp.exec(); // 让硬用程序对象进入消息循环机制中，代码阻塞到当前行`



QT5模块：

![Qt5 模块](pics/01_QT_basic/Qt5%20%E6%A8%A1%E5%9D%97.png)

## 命名规范

类名：首字母大写，驼峰命名

函数名、变量名：首字母小写，驼峰命名



## QTCreator快捷键

| 快捷键              | 功能                   |
| ------------------- | ---------------------- |
| Ctrl+/              | 注释                   |
| Shift+F10           | 运行                   |
| Ctrl+b              | 编译                   |
| Ctrl+shift+上下箭头 | 整行移动               |
| F1                  | 帮助文档               |
| Ctrl+Alt+L          | 自动格式化             |
| F4                  | 头文件和源文件之间切换 |

## 一个简单的Qt程序

```c++
#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
```

解释：

- Qt系统提供的标准类名声明头文件没有.h后缀
- Qt一个类对应一个头文件，类名就是头文件名
- QApplication应用程序类
  - 管理图形用户界面应用程序的控制流和主要设置。
  - 是Qt的整个后台管理的命脉它**包含主事件循环**，在其中来自窗口系统和其它资源的**所有事件处理和调度**。它也处理**应用程序的初始化和结束**，并且**提供对话管理**。
  - 对于任何一个使用Qt的图形用户界面应用程序，都正好存在一个QApplication 对象，而不论这个应用程序在同一时间内是不是有0、1、2或更多个窗口。
- a.exec()
  - **程序进入消息循环**，等待对用户输入进行响应。这里main()把控制权转交给Qt，Qt完成事件处理工作，当应用程序退出的时候exec()的值就会返回。**在exec()中，Qt接受并处理用户和系统的事件并且把它们传递给适当的窗口部件。**

# QPushButton

`#include <QPushButton>`

```c++
QPushButton * btn = new QPushButton; 头文件 #include <QPushButton>

//设置父亲
btn->setParent(this);
//设置文字
btn->setText("德玛西亚");
//移动位置
btn->move(100,100);

//第二种创建
QPushButton * btn2 = new QPushButton("孙悟空",this);
//重新指定窗口大小
this->resize(600,400);

//设置窗口标题
this->setWindowTitle("第一个项目");

//限制窗口大小
this->setFixedSize(600,400);
```

上面代码中，一个按钮其实就是一个QPushButton类下的对象，如果只是创建出对象，是无法显示到窗口中的，所以我们需要依赖一个父窗口，也就是指定一个父亲利用setParent函数即可，如果想设置按钮上显示的文字利用setText，移动按钮位置用move

对于窗口而言，我们可以修改左上角窗口的标题setWindowTitle，重新指定窗口大小：resize，或者设置固定的窗口大小setFixedSize；

## 常见API

```c++
QPushButton *btn = new QPushButton; // 创建
setParent(this); // 设置父亲，依附与窗口
setText("文本"); // 设置按钮文本
btn->move(width, height); // 移动按钮位置
resize(width, height); // 重新指定窗口大小
setWindowTitle("Title"); // 设置窗口标题
setFixedSize(width, height); // 固定窗口大小
btn->resize(width, height); // 重新指定按钮大小
```

