#include <iostream>

using namespace std;

class CMyAdd
{
public:
	int operator()(const int &v1, const int &v2) const
	{ return v1 + v2; }
};

class CMyPrint
{
public:
	CMyPrint()
	{ this->callingTimes = 0; }

	void operator()(const string &str)
	{
		cout << str << endl;
		this->callingTimes++;
	}

	// 函数对象超出普通函数的概念，函数对象可以有自己的状态
	int callingTimes;
};

void doPrint(CMyPrint &myPrint, string str)
{
	myPrint(str);
}

int main()
{
	CMyAdd myAdd;
	// 函数对象在使用时，可以像函数那样调用，可以有参数，可以有返回值
	cout << myAdd(10, 10) << endl;

	CMyPrint myPrint;
	myPrint("Hello World.");
	cout << "Calling times of myPrint: " << myPrint.callingTimes << endl;
	myPrint("Hello World.");
	cout << "Calling times of myPrint: " << myPrint.callingTimes << endl;
	myPrint("Hello World.");
	cout << "Calling times of myPrint: " << myPrint.callingTimes << endl;

	// 函数对象可以作为参数传递
	doPrint(myPrint, "Hello C++.");
	return 0;
}
