# 1. 概述

C++ 11 中的 Lambda 表达式用于定义并创建匿名的函数对象，以简化编程工作。==lambda表达式实际为一个仿函数functor，编译器后会生成一个匿名类（注：这个类重载了()运算符）==
Lambda 的语法形式如下：

```c++
[捕获的外部变量列表] (操作符重载函数参数) mutable 或 exception 声明 -> 返回值类型 {函数体}
[capture] (parameters) specifiers -> return_type { body }
```

可以看到，==Lambda 主要分为五个部分：[函数对象参数]、(操作符重载函数参数)、mutable 或 exception 声明、-> 返回值类型、{函数体}==.



与普通函数指针相比，==Lambda表达式可以包含数据成员，也就是说它是可以有状态的==。下面举一个简单的例子说明一下：

```c++
int sum = 0;
std::vector<int> arry = { 1,2,3,4,5 };
std::for_each(begin(arry), end(arry), [&sum](int x){sum += x;});
```

上述代码被编译器展开后，会变成：

```c++
struct lambda_b53d8cae67476f0e5f04d9defa3a2e2b
{
private:
    int* m_pSum;
public:
    lambda_b53d8cae67476f0e5f04d9defa3a2e2b(int* pSum)
    {
        m_pSum = pSum;
    }

    void operator()(int x) const 
    {
        *m_pSum += x;
    }
};

int sum = 0;
std::vector<int> arry = { 1,2,3,4,5 };
lambda_b53d8cae67476f0e5f04d9defa3a2e2b obj(&sum);
std::for_each(begin(arry), end(arry), obj);
```

# 2. Lambda 语法分析

## 2.1 [捕获的外部变量列表]

标识一个 Lambda 表达式的开始，这部分==必须存在==，不能省略。函数对象参数是传递给编译器自动生成的函数对象类的构造函数的。函数对象参数只能使用那些到定义 Lambda 为止时 Lambda 所在作用范围内可见的局部变量(包括 Lambda 所在类的 this)。函数对象参数有以下形式：

- ==空==。没有任何函数对象参数。
- =====。函数体内可以使用 Lambda 所在范围内所有可见的局部变量（包括 Lambda 所在类的 this），并且是==值传递==方式（相当于编译器自动为我们按值传递了所有局部变量）。
- ==&==。函数体内可以使用 Lambda 所在范围内所有可见的局部变量（包括 Lambda 所在类的 this），并且是==引用传递==方式（相当于是编译器自动为我们按引用传递了所有局部变量）。
- ==this==。函数体内可以使用 ==Lambda 所在类中的成员变量==。
- ==a。将 a 按值进行传递==。按值进行传递时，函数体内不能修改传递进来的 a 的拷贝，因为==默认情况下函数是 const 的，要修改传递进来的拷贝，可以添加 mutable 修饰符==。
- ==&a==。将 a 按引用进行传递。
- a，&b。将 a 按值传递，b 按引用进行传递。
- ===，&a，&b==。除 a 和 b 按引用进行传递外，其他参数都按值进行传递。
- ==&，a，b==。除 a 和 b 按值进行传递外，其他参数都按引用进行传递。

捕获的外部变量列表，通过逗号分隔，可进行传值捕获或者引用捕获，lambda表达式与这些捕获的外部变量会构成一个闭包（Closure），外部变量为闭包的成员变量

```c++
int g_Value = 0;
class CLambda
{
protected:
    int m_Value;
public:
    void Test1(int InValue)
    {
        int Value = 0;
        auto a1 = [](int x) {/*仅能访问全局外部变量*/};
        auto a2 = [Value](int x) {/*值传递局部变量Value*/};
        auto a3 = [this](int x) {/*值传递this指针*/};
        auto a4 = [&Value](int x) {/*引用传递局部变量Value*/};
        auto a5 = [=](int x) {/*值传递所有可访问的外部变量*/};
        auto a6 = [&](int x) {/*引用传递所有可访问的外部变量*/};
        auto a7 = [=, &Value](int x) {/*引用传递局部变量Value，值传递所有其他可访问的外部变量*/};
        auto a8 = [&, Value](int x) {/*值传递局部变量Value，引用传递所有其他可访问的外部变量*/};
    }
};
```

① ==全局变量、静态变量不用显示写在外部变量列表中，可直接在lambda表达式中读写==

② 传值捕获的外部变量是一个副本，默认情况下在lambda表达式中是==只读==的，若想修改该副本，需要在lambda表达式上添加mutable关键字 如：`auto a2 = Value mutable {Value++;};`

③ 在类的非静态成员函数中定义的lambda表达式可以通过捕捉this指针，来访问对象的成员变量和成员函数

④ c++14中增加广义捕获（Generalized capture）：即在捕获子句中增加并初始化新的变量，该变量不需要在lambda表达式所处的闭包域中存在；即使在闭包域中存在也会被新变量覆盖。新变量类型由它的初始化表达式推导得到。一个用途是可以从闭包域中捕获只供移动的变量并使用它。

```c++
int Value = 0;
auto a1 = [Value = 100] { return Value; };// 捕获子句中定义的Value变量会覆盖同名的外部局部变量
int result = a1(); // result=100

std::vector<int> Vout = { 10, 20, 30, 40, 50 };
auto a2 = [Vin = std::move(Vout)]{ // 将外部局部变量Vout移动到Vin变量，避免发生拷贝耗时操作
    int sum = 0;
    for (auto n : Vin)
    {
        sum += n;
    }

    return sum;
};

int result2 = a2(); // result2=150
```



## 2.2 (操作符重载函数参数)

标识重载的 () 操作符的参数，没有参数时，这部分可以省略。参数可以通过==按值==（如: (a, b)）和==按引用== (如: (&a, &b)) 两种方式进行传递。

1. 若lambda函数没有形参且没有被mutable等修饰，则参数的空圆括号可以省略

如：auto a = []{ ++g_Value; };

2. c++14支持auto类型的形参

```c++
auto a = [](auto x, auto y) {return x + y;};

//相当于定义了模板类型()运算符的函数对象
struct unnamed_lambda                            
{
  template<typename T, typename U> 
  auto operator()(T x, U y) const {return x + y;}
} a;
```

3. c++14支持可变参数模板

```c++
int foo(int n1, int n2, bool flag)
{
    return flag ? n1 : n2;
}

auto a = [](auto&&... params) //可变参数的模板
{
    return (foo(std::forward<decltype(params)>(params)...));
};
int result = a(1, 2, true); //result=1
```

4. 与普通函数相比，lambda表达式的参数有如下限制

   ① 参数不能有缺省值  如：int Add1(int a, int b=10) 

   ② 不能有可变长参数列表 如：int Add2(int count, ...)

   ③ 不能有无名参数 如：int Add3(int a, int b, int) // 第三个参数为无名参数，用于以后扩展

## 2.3 mutable 或 exception 声明

这部分可以省略。==按值传递函数对象参数时，加上 mutable 修饰符后，可以修改传递进来的拷贝==（注意是==能修改拷贝，而不是值本身==）。exception 声明用于指定函数抛出的异常，如抛出整数类型的异常，可以使用 throw(int)。

在C++中，mutable是为了突破const的限制而设置的，用来修饰类的非静态、非常量的数据成员，让被修饰的变量永远处于可变的状态

mutable的作用有两点：
a. 保持常量对象中大部分数据成员仍然是“只读”的情况下，实现对个别数据成员的修改；
b. 使类的const函数可以修改其mutable数据成员。

## 2.4 -> 返回值类型

标识函数返回值的类型，当返回值为 void，或者函数体中只有一处 return 的地方（此时编译器可以自动推断出返回值类型）时，这部分可以省略。

## 2.5 {函数体}

标识函数的实现，这部分不能省略，但函数体可以为空。

# 3. 使用lambda表达式

lambda表达式实际为一个函数对象，在使用时要注意lambda表达式以及被其捕获的外部变量的生命周期

**把匿名函数存储在变量，当做有名函数来使用**

==lambda表达式的数据类型是函数对象，可用auto类型、std::function模板类型（需#include <functional>）进行保存和调用==

==当捕获外部变量列表为空时，也可用普通函数指针进行保存和调用==

```c++
int Value = 0;

auto a1 = [&Value](int x) {Value = x;};
std::function<float(int,float)> a2 = [Value](int x, float y) { return x + y; }; //需要#include <functional>
a1(100);
a2(100, 200.0f);

// lambda函数的捕获外部变量列表为空时，可使用普通函数指针来保存
int(*func1_ptr)(int) = [](int x) {return x; };
bool(*func2_ptr)(int, int) = [](int x, int y) { return x > y; };
int n = func1_ptr(1);
bool b = func2_ptr(1, 2);
```

**悬挂引用问题**

lambda表达式的闭包含有局部变量的引用（悬挂引用 Dangling references），在超出创建它的作用域之外的地方被使用的话，将引发内存越界访问

```c++
std::function<int()> a;
{
    int Value = 0;
    a = [&Value] {return Value; };
}
        
a(); // 局部变量Value超过作用域，已被回收，调用lambda表达式将产生内存越界访问
```

对于使用lambda表达式写的回调函数（如：窗口处理函数、线程执行函数、控件消息处理函数等），尤其要注意这个问题

# 4. 示例

```c++
[] (int x, int y) { return x + y; } // 隐式返回类型
[] (int& x) { ++x;  } // 没有 return 语句 -> Lambda 函数的返回类型是 'void'
[] () { ++global_x;  } // 没有参数，仅访问某个全局变量
[] { ++global_x; } // 与上一个相同，省略了 (操作符重载函数参数)
```

可以像下面这样显示指定返回类型：

```c++
[] (int x, int y) -> int { int z = x + y; return z; }
```

在这个例子中创建了一个临时变量 z 来存储中间值。和普通函数一样，这个中间值不会保存到下次调用。什么也不返回的
Lambda 函数可以省略返回类型，而不需要使用 -> void 形式。

Lambda 函数可以引用在它之外声明的变量. 这些变量的集合叫做一个==闭包==. 闭包被定义在 Lambda 表达式声明中的方括号 [] 内。这个机制允许这些变量被按值或按引用捕获。如下图的例子：
![img](pics/Cxx%E4%B9%8Blambda%E8%A1%A8%E8%BE%BE%E5%BC%8F/1382048-20180509221109509-1786172899.jpg)

```c++
std::vector<int> some_list;
int total = 0;
for (int i = 0; i < 5; ++i) some_list.push_back(i);
std::for_each(begin(some_list), end(some_list), [&total](int x)
{
    total += x;
});
```

此例计算 list 中所有元素的总和。==变量 total 被存为 Lambda 函数闭包的一部分。因为它是栈变量（局部变量）total 引用，所以可以改变它的值==。

```c++
std::vector<int> some_list;
int total = 0;
int value = 5;
std::for_each(begin(some_list), end(some_list), [&, value, this](int x)
{
    total += x * value * this->some_func();
});
```

此例中 total 会存为引用, value 则会存一份值拷贝。对 this 的捕获比较特殊，它只能按值捕获。this 只有当包含它的最靠近它的函数不是静态成员函数时才能被捕获。对 protect 和 private 成员来说，这个 Lambda 函数与创建它的成员函数有相同的访问控制。如果 this 被捕获了，不管是显式还是隐式的，那么它的类的作用域对 Lambda 函数就是可见的。访问 this 的成员不必使用 this-> 语法，可以直接访问。

# 5. 总结

不同编译器的具体实现可以有所不同，但期望的结果是: 按引用捕获的任何变量，Lambda 函数实际存储的应该是这些变量在创建这个 Lambda 函数的函数的栈指针，而不是 Lambda 函数本身栈变量的引用。不管怎样，因为大多数 Lambda 函数都很小且在局部作用中，与候选的内联函数很类似，所以按引用捕获的那些变量不需要额外的存储空间。

如果一个闭包含有局部变量的引用，在超出创建它的作用域之外的地方被使用的话，这种行为是未定义的!

Lambda 函数是一个依赖于实现的函数对象类型,这个类型的名字只有编译器知道. 如果用户想把 lambda 函数做为一个参数来传递, 那么形参的类型必须是模板类型或者必须能创建一个std::function 类似的对象去捕获 lambda 函数.==使用 auto 关键字可以帮助存储 lambda 函数==,

```c++
auto my_lambda_func = [&](int x) { /* ... */ };
auto my_onheap_lambda_func = new auto([=](int x) { /* ... */ });
```

这里有一个例子, 把匿名函数存储在变量、数组或 vector 中,并把它们当做命名参数来传递
![img](pics/Cxx%E4%B9%8Blambda%E8%A1%A8%E8%BE%BE%E5%BC%8F/1382048-20180509222452588-1779542133.jpg)

一个没有指定任何捕获的 lambda 函数,可以显式转换成一个具有相同声明形式函数指针.所以,像下面这样做是合法的:

```c++
auto a_lambda_func = [](int x) { /* ... */ };
void (*func_ptr)(int) = a_lambda_func;
func_ptr(4); // calls the lambda
```

