/**
 * @file    指向成员函数的指针的长度_多继承与虚继承对指向成员函数的函数指针的影响
 * @brief   
 * @details 
 * @author  Jack Zhang
 * @email   zhangmengwei1996@outlook.com
 * @version 1.0.0
 * @date    3/13/21
 * @license GNU General Public License (GPL)
 */
#include <iostream>

class Test; //一个未定义的类。

class Test2
{
private:
	int i;
public:
	void foo() { std::cout << "Test 2 foo()." << std::endl;}
};

class Test3
{
private:
	int i;
public:
	void foo() {std::cout << "Test 3 foo()." << std::endl;}
};


class Test4 : public Test2, public Test3 //多继承的类
{
private:
	int i;
public:
	void foo() {std::cout << "Test 4 foo()." << std::endl;}
};

class Test5 : virtual public Test4 //虚继承的类
{
private:
	int i;
public:
	void foo() {std::cout << "Test 5 foo()." << std::endl;}
};

int main()
{
	std::cout << "Test3类成员函数指针长度=" << sizeof(void (Test3::*)()) << '\n';
	std::cout << "Test4类成员函数指针长度=" << sizeof(void (Test4::*)()) << '\n';
	std::cout << "Test5类成员函数指针长度=" << sizeof(void (Test5::*)()) << '\n';
	std::cout << "Test类成员函数指针长度=" << sizeof(void (Test::*)()) << '\n';

	//以下可以打开IDE的反汇编（Disassembly）窗口观察成员函数指针的赋值与调用
	Test5 a;                                                             //定义一个实例
	void (Test5::* pfunc)() =&Test5::foo;                //定义类成员函数指针并赋值

	(a.*pfunc)();  //调用类成员函数指针，同时使用了虚基表（vbtbl）索引值与this指针调整值
}
