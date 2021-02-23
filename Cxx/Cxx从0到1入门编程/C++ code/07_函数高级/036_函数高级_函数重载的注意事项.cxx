// 函数重载注意事项
#include <iostream>

using namespace std;

void fun(int &a)
{
    cout << "fun(int &) calling" << endl;
}

// 引用可以作为函数重载的条件
void fun(const int &a)
{
    cout << "fun(const int &) calling" << endl;
}

// 注意下面两个函数，不调用的话语法上通过
// 但调用的时候会出问题
void func2(int a, int b = 10)
{
    cout << "Calling func2" << endl;
}

void func2(int a)
{
    cout << "Calling func2" << endl;
}

int main(int argc, char **argv)
{
    int a = 10;
    fun(a); // 调用fun(int &a)
    const int b = 20;
    fun(b); // 调用fun(const int &a)
    fun(10); // 调用fun(const int &a)

    func2(12, 12);
    // func2(10); // 函数重载遇到默认参数，出现二义性，尽量避免这种情况
    return 0;
}
