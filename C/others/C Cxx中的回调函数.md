在理解“回调函数”之前，首先讨论下函数指针的概念。

## **函数指针**

（1）概念：指针是一个变量，是用来指向内存地址的。一个程序运行时，所有和运行相关的物件都是需要加载到内存中，这就决定了程序运行时的任何物件都可以用指针来指向它。函数是存放在内存代码区域内的，它们同样有地址，因此同样可以用指针来存取函数，把这种指向函数入口地址的指针称为函数指针。

（2）先来看一个Hello World程序采用函数调用的形式来实现：

```c
void Invoke(char* s);

int main(int argc,char* argv[])
{
    Invoke("Hello World!\n");
    return 0;
}

void Invoke(char* s)
{
    printf(s);
}
```

用函数指针的方式来实现：

```c
void Invoke(char* s);

int main()
{
    void (*fp)(char* s);    //声明一个函数指针(fp)        
    fp=Invoke;              //将Invoke函数的入口地址赋值给fp
    fp("Hello World!\n");   //函数指针fp实现函数调用
    return 0;
}

void Invoke(char* s)
{
    printf(s);
}
```

由上知道：函数指针函数的声明之间唯一区别就是，用指针名`（*fp）`代替了函数名`Invoke`，这样这声明了一个函数指针，然后进行赋值`fp=Invoke`就可以进行函数指针的调用了。声明函数指针时，只要函数返回值类型、参数个数、参数类型等保持一致，就可以声明一个函数指针了。注意，函数指针必须用括号括起来` void (*fp)(char* s)`。

   实际中，为了方便，通常用宏定义的方式来声明函数指针，实现程序如下：

```c
typedef void (*FP)(char* s);
void Invoke(char* s);

int main(int argc,char* argv[])
{
    FP fp;      //通常是用宏FP来声明一个函数指针fp
    fp=Invoke;
    fp("Hello World!\n");
    return 0;
}

void Invoke(char* s)
{
    printf(s);
}
```

**函数指针数组**

下面用程序对函数指针数组来个大致了解：

```c
#include <iostream>
#include <string>
using namespace std;

typedef void (*FP)(char* s);
void f1(char* s){cout<<s;}
void f2(char* s){cout<<s;}
void f3(char* s){cout<<s;}

int main(int argc,char* argv[])
{
    void* a[]={f1,f2,f3};   //定义了指针数组，这里a是一个普通指针
    a[0]("Hello World!\n"); //编译错误，指针数组不能用下标的方式来调用函数

    FP f[]={f1,f2,f3};      //定义一个函数指针的数组，这里的f是一个函数指针
    f[0]("Hello World!\n"); //正确，函数指针的数组进行下标操作可以进行函数的间接调用
    
    return 0;
}
```

## **回调函数**

（1）概念：回调函数，顾名思义，就是使用者自己定义一个函数，使用者自己实现这个函数的程序内容，然后把这个函数作为参数传入别人（或系统）的函数中，由别人（或系统）的函数在运行时来调用的函数。函数是你实现的，但由别人（或系统）的函数在运行时通过参数传递的方式调用，这就是所谓的回调函数。简单来说，就是由别人的函数运行期间来回调你实现的函数。

（2）标准Hello World程序修改成函数回调样式：

```c
//定义回调函数
void PrintfText() 
{
    printf("Hello World!\n");
}

//定义实现回调函数的"调用函数"
void CallPrintfText(void (*callfuct)())
{
    callfuct();
}

//在main函数中实现函数回调
int main(int argc,char* argv[])
{
    CallPrintfText(PrintfText);
    return 0;
}
```

   修改成带参的回调样式：

```c
//定义带参回调函数
void PrintfText(char* s) 
{
    printf(s);
}

//定义实现带参回调函数的"调用函数"
void CallPrintfText(void (*callfuct)(char*),char* s)
{
    callfuct(s);
}

//在main函数中实现带参的函数回调
int main(int argc,char* argv[])
{
    CallPrintfText(PrintfText,"Hello World!\n");
    return 0;
}
```

### 为什么要使用回调函数？

很多朋友可能会想，为什么不像普通函数调用那样，在回调的地方直接写函数的名字呢？这样不也可以吗？为什么非得用回调函数呢？有这个想法很好，因为在网上看到解析回调函数的很多例子，其实完全可以用普通函数调用来实现的。要回答这个问题，我们先来了解一下回到函数的好处和作用，那就是解耦，对，就是这么简单的答案，就是因为这个特点，普通函数代替不了回调函数。所以，在我眼里，这才是回调函数最大的特点。来看看维基百科上面我觉得画得很好的一张图片。

![img](pics/C%20Cxx%E4%B8%AD%E7%9A%84%E5%9B%9E%E8%B0%83%E5%87%BD%E6%95%B0/2ecc00017db499f2620d.jpeg)

下面以一段不完整的 C 语言代码来呈现上图的意思：

```c
#include<stdio.h>
#include<softwareLib.h> // 包含Library Function所在读得Software library库的头文件

int Callback() *// Callback Function*
{
  *// TODO*
  return 0;
}
int main() *// Main program*
{
  *// TODO*
  Library(Callback);
  *// TODO*
  return 0;
}
```

乍一看，回调似乎只是函数间的调用，和普通函数调用没啥区别，但仔细一看，可以发现两者之间的一个关键的不同：在回调中，主程序把回调函数像参数一样传入库函数。这样一来，只要我们改变传进库函数的参数，就可以实现不同的功能，这样有没有觉得很灵活？并且丝毫不需要修改库函数的实现，这就是解耦。再仔细看看，主函数和回调函数是在同一层的，而库函数在另外一层，想一想，如果库函数对我们不可见，我们修改不了库函数的实现，也就是说不能通过修改库函数让库函数调用普通函数那样实现，那我们就只能通过传入不同的回调函数了，这也就是在日常工作中常见的情况。现在再把main()、Library()和Callback()函数套回前面 F1、F2和F3函数里面，是不是就更明白了？

明白了回调函数的特点，是不是也可以大概知道它应该在什么情况下使用了？没错，你可以在很多地方使用回调函数来代替普通的函数调用，但是在我看来，如果需要降低耦合度的时候，更应该使用回调函数。