/**
 * @file    一个类中定义一个函数指针绑定另一个类的成员函数.cpp.c
 * @brief   
 * @details 
 * @author  Jack Zhang
 * @email   zhangmengwei1996@outlook.com
 * @version 1.0.0
 * @date    3/13/21
 * @license GNU General Public License (GPL)
 */
#include <iostream>

class A;

class B
{
public:
	/// B中的成员变量，指向A类中的print成员函数
	void (A::* pAPrint)(const char *);
};

class A
{
public:
	void set()
	{
		B b{};
		// 将B类中的成员变量绑定到A类中的成员函数
		b.pAPrint = &A::print;
		// 指向类成员函数的指针的调用方式，注意不要忘记括号
		(this->*b.pAPrint)("Hello World!");
	}

private:
	void print(const char *msg) { std::cout << msg << std::endl; }
};

int main()
{
	A a;
	a.set();

	return 0;
}