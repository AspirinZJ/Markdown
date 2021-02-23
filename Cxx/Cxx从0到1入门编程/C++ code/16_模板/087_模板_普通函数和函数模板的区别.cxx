// 普通函数可以发生隐式类型转换
// 模板函数如果用隐式类型推导，不能发生隐式类型转换
// 模板函数如果用显式指定类型，可以发生隐式类型转换
#include <iostream>
using namespace std;

int addInt(int a, int b) {return a+b;}

template<typename T>
T addT(T a, T b) {return (a+b);}

void test1()
{
    int a = 1, b = 2;
    cout << addInt(a, b) << endl;
    char c = 'r';
    cout << addInt(a, c) << endl; // 普通函数调用发生了隐式类型转换，把'r'的ASCII码转换成了int类型
}

void test2()
{
    int a = 1, b = 2;
    cout << addT(a, b) << endl;
    char c = 'r';
    // cout << addT(a, c) << endl; // 模板函数的自动类型推导不能发生隐式类型转换
    cout << addT<int>(a, c) << endl; // 模板函数的显式指定类型可以发生隐式类型转换
}

int main()
{
    test1();
    return 0;
}
