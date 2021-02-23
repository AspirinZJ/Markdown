// 函数调用运算符重载
#include <iostream>
using namespace std;

class MyPrint
{
    public:
        // 重载函数调用运算符
        void operator()(string str) {cout << str << endl;}
};

class MyAddFunc
{
    public:
        int operator()(int num1, int num2) {return num1 + num2;}
};

void test1()
{
    MyPrint myPrint;
    myPrint("Hello World!"); // 由于使用起来非常像函数调用，所以叫仿函数
    // 仿函数非常灵活，没有固定写法
    MyAddFunc addFunc;
    cout << (addFunc(10, 10)) << endl;

    // 匿名函数对象, MyAddFunc()是一个匿名对象
    cout << MyAddFunc()(100, 100) << endl;
}

int main()
{
    test1();
    return 0;
}
