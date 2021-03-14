#include <iostream>

class MyClass
{
public:
	/// 类静态成员函数， 其函数指针的使用方式和普通的全局函数相同
	static int staticMemFun(int a, int b)
	{
		std::cout << "call static member: staticMemFun." << std::endl;
		return a + b;
	}

	/// 类非静态成员函数，获取函数指针时前面要加上类名::*
	void memFun1() { std::cout << "call non-static member: memFun1." << std::endl; }

	int memFun2(int a, int b)
	{
		std::cout << "call non-static member: memFun2." << std::endl;
		return a + b;
	}

	int staticMemTest(int (*p)(int, int), int a, int b)
	{
		return (*p)(a, b);
	}

	void nonStaticMemTest1(void (MyClass::*nonstatic)())
	{
		(this->*nonstatic)();
	}

	void nonStaticMemTest2(int (MyClass::* pNonStatic)(int, int), int a, int b)
	{
		std::cout << a << " + " << b << " = " << (this->*pNonStatic)(a, b) << std::endl;
	}
};

int main()
{
	auto *pMyClass = new MyClass;

	// 静态成员函数指针的使用， 和普通全局函数获取函数指针的方式相同
	int (*pStaticMemFun)(int, int) = &MyClass::staticMemFun;
	std::cout << pStaticMemFun(1, 2) << std::endl;

	// 非静态成员函数指针的使用, 前面要加上 类名::*
	void (MyClass::* pMemFun1)() = &MyClass::memFun1;
	(pMyClass->*pMemFun1)();

	// 通过 staticMemTest 只能调用静态方法,注意函数里指针变量的声明方式
	pMyClass->staticMemTest(&MyClass::staticMemFun, 1, 2);

	// 通过 nonStaticMemTest1 就是调用成员方法, 注意函数里指针变量的生命方式
	pMyClass->nonStaticMemTest1(&MyClass::memFun1);
	pMyClass->nonStaticMemTest2(&MyClass::memFun2, 1, 2);

	delete pMyClass;
	return 0;
}