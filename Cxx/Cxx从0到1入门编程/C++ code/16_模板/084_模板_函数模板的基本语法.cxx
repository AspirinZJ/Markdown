#include <iostream>
using namespace std;

// void swapInt(int &a, int &b)
// {int tmp = a; a = b; b = tmp;}
// 
// void swapFloat(float &a, float &b)
// {float tmp = a; a = b; b = tmp;}

// 函数模板
template<typename T> // 声明一个模板，T是一个通用的数据类型
void swapT(T &a, T &b) {T tmp = a; a = b; b = tmp;}

int main()
{
    int a = 1, b = 0;
    // 两种函数使用函数模板
    // 1. 自动类型推导
    swapT(a, b);
    cout << "a: " << a << ". b: " << b << endl;

    float c = 10, d = 20;
    // 2. 显式指定类型
    swapT<float>(c, d);
    cout << "c: " << c << ". d: " << d << endl;
    
    return 0;
}
