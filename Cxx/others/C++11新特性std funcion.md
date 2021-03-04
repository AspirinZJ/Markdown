std::function来实现回调函数。==类模版==std::function是一种==通用、多态==的函数封装。std::function的实例可以对任何可以调用的目标实体进行存储、复制、和调用操作，这些目标实体包括==普通函数、Lambda表达式、函数指针、以及其它函数对象等==。std::function对象是对C++中现有的可调用实体的一种类型安全的==包裹==（我们知道像函数指针这类可调用实体，是类型不安全的）。函数指针只能指向一个函数，而std::function对象可以代表任何可以调用的对象，比如说任何可以被当作函数一样调用的对象。

通常std::function是一个函数对象类，它包装其它任意的函数对象，被包装的函数对象具有类型为T1, …,TN的N个参数，并且返回一个可转换到R类型的值。std::function使用 模板转换构造函数接收被包装的函数对象；特别是，闭包类型可以隐式地转换为std::function。

最简单的理解就是：

通过std::function对C++中各种可调用实体（普通函数、Lambda表达式、函数指针、以及其它函数对象等）的封装，形成一个新的可调用的std::function对象；让我们不再纠结那么多的可调用实体。

lambda表达式产生了可调用的对象，这个对象这里称做一个闭包（closure），可以保存在std::function对象里面。==closure（闭包）的定义是，一个函数和它所引用的非本地变量（非lambda表达式内部定义的变量）的一个集合。==

# 使用std::function作为函数入参

## 基于传值的方式传递参数

参看下面一段代码，实现了一个注册回调函数的机制，

```c++
#include <functional>
void registerCallBack(std::function<void()>);
```

入参std::function<void()>是一个模板类对象，它可以用一个函数签名为void()的可调用对象来进行初始化；上述实现里面是一个传值调用。我们来看一下它的调用过程，

```c++
// 方法（A）
registerCallBack([=]{
    ....  // 回调函数的实现部分
})
```

这里使用了lambda表达式作为函数的入参，正如前面所说的lambda表达式会生成一个匿名的闭包（closure），基于这个闭包构造了一个std::function<void()>的对象，然后通过传值调用的方式把这个对象传递registerCallBack函数中使用。

## 基于引用的方式传递参数

当然我们还可以如下实现这个注册函数，入参通过const引用的方式传递，==这里的引用必须是const的，这是因为调用registerCallBack函数的地方生成了一个临时的std::function()对象，是一个右值==，否则编译会报错。

```c++
//方法(B)
void registerCallBack(std::function<void()> const&)
```

这两者的区别就在于，在registerCallBack函数内部怎么使用这个入参，如果只是简单的调用一下std::func()类，那么两种都没有问题，可能使用引用的效率更高；如果register函数内部需要保存这个std::func()，并用于以后使用，那么方法A直接保存没有问题，方法B就必须做一次拷贝，否则方法B中，当临时的对象销毁时，有可能出现引用悬空的问题。

## 传值方式下的std::function对象保存

如果我们要在registerCallBack函数内部保存这个传入的function对象，我们可以使用转移操作std::move，这样的效率更高，

```c++
class CallBackHolder 
{
public:
  void registerCallBack(std::function<void()> func)
  {
    callback = std::move(func);
  } 
private:
  std::function<void()> callback; 
```

# 类的成员函数作为函数入参

类的成员函数都会默认有个隐藏的this指针，所以不像普通的函数直接作为入参就可以了。

## 使用std::bind()和std::function来实现

std::function是通用的多态函数封装器，它的实例可以存储、复制以及调用任何可以调用的目标：函数，lambda表达式/bind表达式或其他函数对象，还有指向成员函数指针和指向数据成员指针；
std::bind接受一个函数（或者函数对象），生成一个重新组织的函数对象；
看下面一个例子，classA提供了一个注册函数，用来注册一个回调函数

```c++
class classA
{
typedef std::function<void(int i)> callback_t;
...
    void registCb(callback_t func)
    {cbHandle = std::move(func);}
private:
    callback_t cbHandle;
};
```

另一个类classB需要注册自己的一个成员函数作为回调函数到classA中，这里就可以使用std::bind函数来实现，

```c++
class classB
{
public:
    classB(classA& cA) 
    {       
        cA.registCb(std::bind(&classB::handle, this, std::placeholders::_1));
    }
};
```

- bind函数中显示的传递classB的this指针作为第一个参数给回调函数；
- std::placeholders:_1代表一个占位符，用于回调函数显式的入参；

Effective Modern C++中专门有一节解释过std::bind的方式比较繁琐，并且有时侯会有一些局限性，所以在引入了lambda表达式后就可以用lambda表达式来替代std::bind实现函数回调注册。

## 使用lambda表达式实现

使用lambda表达式的方式可以简化这一个过程，参看如下一段代码，classB注册一个成员函数作为回调函数到classA中，classA会保存这个回调函数（std::function对象）到成员变量中，用于后面使用，

```c++
#include <iostream>
#include <functional>
#include <memory>

class classA
{
typedef std::function<void(int i)> callback_t;
public:
    classA() {}
    ~classA() {}
    void handle(int i)
   {
       std::cout << "classA::handle" << std::endl;
       cbHandle(i);
   }
    void registCb(callback_t func)
    {cbHandle = std::move(func);}
private:
    callback_t cbHandle;
};

class classB
{
public:
    classB(classA& cA) 
    {       
       cA.registCb([this](int i){classB::handle(i);});
    }

    ~classB() {}

   void handle(int i)
   {
       std::cout << "classB, handle message" << i << std::endl;
   }
};

int main()
{
    classA testa;
    classB testb(testa);
    testa.handle(10);
}
```

- lambda表达式中捕获了classB的this指针
- 使用std::move的方式保存function对象到classA中





```c++
#include <functional>
#include <iostream>
using namespace std;

std::function<int(int)> Functional;

// 普通函数
int TestFunc(int a)
{
    return a;
}

// Lambda表达式
auto lambda = [](int a) -> int { return a; };

// 仿函数(functor)
class Functor
{
public:
    int operator()(int a)
    {
        return a;
    }
};

// 1.类成员函数
// 2.类静态函数
class TestClass
{
public:
    int ClassMember(int a) { return a; }
    static int StaticMember(int a) { return a; }
};

int main()
{
    // 普通函数
    Functional = TestFunc;
    int result = Functional(10);
    cout << "普通函数：" << result << endl;
    
    // Lambda表达式
    Functional = lambda;
    result = Functional(20);
    cout << "Lambda表达式：" << result << endl;

    // 仿函数
    Functor testFunctor;
    Functional = testFunctor;
    result = Functional(30);
    cout << "仿函数：" << result << endl;

    // 类成员函数
    TestClass testObj;
    Functional = std::bind(&TestClass::ClassMember, testObj, std::placeholders::_1);
    result = Functional(40);
    cout << "类成员函数：" << result << endl;

    // 类静态函数
    Functional = TestClass::StaticMember;
    result = Functional(50);
    cout << "类静态函数：" << result << endl;

    return 0;
}
```
关于可调用实体转换为std::function对象需要遵守以下两条原则：

- 转换后的std::function对象的参数能转换为可调用实体的参数；
- 可调用实体的返回值能转换为std::function对象的返回值。

std::function对象最大的用处就是在实现函数回调（实际工作中就是用到了这一点），使用者需要注意，它不能被用来检查相等或者不相等，但是可以与NULL或者nullptr进行比较。