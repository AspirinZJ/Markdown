#include <iostream>

using namespace std;

class Person
{
public:
	virtual void print()
	{ cout << "Person." << endl; }
};

class Student : public Person
{
public:
	virtual void print()
	{ cout << "Student.\n"; }
};

class Teacher : public Person
{
public:
	virtual void print()
	{ cout << "Teacher.\n"; }
};

int main()
{
	Student s1, s2;
	Teacher t1, t2, t3;
	Person *personArr[5] = {&s1, &t2, &t1, &s2, &t3};

	for (int i = 0; i < 5; ++i) // 只打印老师的数据, 使用动态转型
	{
		// 转型失败时返回NULL
		if (dynamic_cast<Teacher *>(personArr[i])) personArr[i]->print();
	}

	cout << "---------------------------------" << endl;

	for (int i = 0; i < 5; ++i) // 静态转型会强制转换
	{
		// 静态转型会强制转换
		if (static_cast<Teacher *>(personArr[i])) personArr[i]->print();
	}

	return 0;
}