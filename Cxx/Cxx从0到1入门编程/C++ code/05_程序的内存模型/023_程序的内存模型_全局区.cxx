// 全局区
// 存放全局变量，静态变量和常量
// g: global, c: const
#include <iostream>

using namespace std;

// 全局变量（函数体外）
int gA = 10, gB = 20;
int gcA = 10, gcB = 10; // 全局常量

int main()
{

	int a = 10, b = 10;	// 普通局部变量（函数体内部的变量）
	cout << "局部变量的地址, a: " << &a << ". b: " << &b << endl;
	cout << "全局变量的地址, gA: " << &gA << ". gB: " << &gB << endl; // 存放在全局区


    // 静态变量 static修饰
    static int sA = 10, sB = 10;
	cout << "静态变量的地址, sA: " << &sA << ". sB: " << &sB << endl; // 存放在全局区

    // 常量
    // 字符串常量
    cout << "字符串常量的地址为：" << &"Hello World" << endl; // 存放在全局区

    // const 修饰的变量
    // 1. const修饰的全局变量
    // gcA
    cout << "全局const变量地址为: gcA: " << &gcA << ". gcB: " << &gcB << endl;// 存放在全局区
    // 2. const修饰的局部变量
    const int cA = 10, cB = 20;
    cout << "局部const变量地址为: cA: " << &cA << ". cB: " << &cB << endl;

    return 0;
}
