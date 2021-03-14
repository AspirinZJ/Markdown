/**
 * @file    simpleExamples.cpp.c
 * @brief	展示了类的静态成员函数、非静态成员函数和虚函数的函数指针绑定方式和调用方式
 * @details
 * @author  Jack Zhang
 * @email   zhangmengwei1996@outlook.com
 * @version 1.0.0
 * @date    3/13/21
 * @license GNU General Public License (GPL)
 */
#include <iostream>

class A
{
public:
	static void staticMethod() { std::cout << "static" << std::endl; } // 静态成员函数

	void nonStaticMethod() { std::cout << "nonstatic" << std::endl; } // 普通成员函数

	virtual void virtualMethod() { std::cout << "virtual" << std::endl; } // 虚函数
};


int main()
{
	A a;

	//static成员函数,取得的是该函数在内存中的实际地址，而且因为static成员是全局的，所以不能用A::限定符
	void (*ptrStatic)() = &A::staticMethod;

	//nonStaticMethod 成员函数 取得的是该函数在内存中的实际地址
	void (A::*ptrMethod)() = &A::nonStaticMethod;

	//虚函数取得的是虚函数表中的偏移值，这样可以保证能过指针调用时同样的多态效果
	void (A::*ptrVirtual)() = &A::virtualMethod;


	//函数指针的使用方式
	ptrStatic(); // 静态成员函数
	(a.*ptrMethod)(); // 非静态成员函数
	(a.*ptrVirtual)(); // 虚函数
}
