// 注意：动态类型转换dynamic_cast的时候必须有虚函数支持
#include <iostream>
using namespace std;

class Base
{
public:
	virtual void print() const {cout << "Base class.\n";}
	void outBase() const { cout << "outBase.\n";}
private:
};

class Derived1 : public Base
{
public:
	virtual void print() const {cout << "Derived1 class.\n";}
	void outDerived1() const {cout << "outDerived1.\n";}
private:
};

class Derived2 : public Base
{
public:
	virtual void print() const {cout << "Derived2 class.\n";}
	void outDerived2() const {cout << "outDerived2.\n";}
private:
};

int main()
{
	Derived1 d1;
	Derived2 d2;
	const Derived1 *p1;
	const Derived2 *p2;
	Base *baseArr[2] = {&d1, &d2};
	for (int i = 0; i < 2; ++i)
	{
		if ((p1 = dynamic_cast<Derived1 *>(baseArr[i]))) // baseArr[0]可以转换成Derived1 *
		{
			p1->print();
			p1->outDerived1();
		}
		else if((p2 = dynamic_cast<Derived2 *>(baseArr[i]))) // baseArr[0]不可以转换成Derived2 *
		{
			p2->print();
			p2->outDerived2();
		}
	}

	return 0;
}
