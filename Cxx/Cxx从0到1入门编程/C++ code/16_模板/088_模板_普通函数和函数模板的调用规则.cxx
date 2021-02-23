// 如果普通函数和函数模板都能调用，优先调用普通函数
// 可以通过空模板参数列表强制调用函数模板
// 函数模板可以发生重载
// 如果函数模板可以发生更好的匹配，优先调用函数模板
#include <iostream>
using namespace std;

void myPrint(int a, int b) {cout << "Calling function." << endl;}

template<typename T>
void myPrint(T a, T b) {cout << "Calling function template." << endl;}

// 函数模板可以发生重载
template<typename T>
void myPrint(T a, T b, T c) {cout << "Calling function template." << endl;}

void myPrint2(int a, int b);

template<typename T>
void myPrint2(T a, T b) {cout << "Calling function2 template." << endl;}

void test1()
{
    int a = 1, b = 2;
    myPrint(a, b); // 函数模板和普通函数都能调用，优先调用普通函数
    // myPrint2(a, b); // 报错，因为优先调用普通函数，而普通函数只有声明没有实现
    
    // 通过空模板参数列表，强制调用函数模板
    myPrint<>(a, b);

    myPrint(a, b, 5); // 函数模板可以发生重载

    char c1 = 'a', c2 = 'b';
    myPrint(c1, c2); // 如果函数模板能够发生更好的匹配，优先调用函数模板（发生了隐式类型推导）
}

int main()
{
    test1();
    return 0;
}
