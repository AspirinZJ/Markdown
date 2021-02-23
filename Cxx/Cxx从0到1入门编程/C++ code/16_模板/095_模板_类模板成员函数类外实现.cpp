#include <iostream>
using namespace std;

template<class T1, class T2>
class Person
{
public:
	Person(T1 name, T2 age);
	void showPerson() ;
	T1 m_name;
	T2 m_age;
};

// 构造函数类外实现
template<class T1, class T2> // 需要在上面加上template
Person<T1, T2>::Person(T1 name, T2 age) // 用尖括号表示这是类模板成员函数的类外实现
{
	this->m_name = name;
	this->m_age = age;
}

// 成员函数的类外实现
template<class T1, class T2>
void Person<T1, T2>::showPerson() {cout << "Name: " << this->m_name << ". Age: " << this->m_age << endl;}

void test1()
{
	Person<string, int> person("Alice", 19);
	person.showPerson();
}

int main()
{
	test1();
    return 0;
}
