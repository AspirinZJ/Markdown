// 函数重载
#include <iostream>

using namespace std;

void func()
{
    cout << "Calling func." << endl;
}

// 函数重载的条件：
// 1. 必须在同一个作用域下（现在是全局作用域）
// 2. 函数名称相同
// 3. 函数参数类型不同，或者个数不同，或者顺序不同
void func(int a)
{
    cout << "int a: " << a <<  endl;
}

void func(char a)
{
    cout << "char a: " << a <<  endl;
}

void func(int a, float b)
{
    cout << "int a:" << a << " double b:" << b << endl;
}

void func(float a, int b)
{
    cout << "float a:" << a << "int b:" << b << endl;
}

int main(int argc, char **argv)
{
    func();
    func(20);
    func('a');
    func(10, 10.0);
    func(10.0, 10);
    return 0;
}
