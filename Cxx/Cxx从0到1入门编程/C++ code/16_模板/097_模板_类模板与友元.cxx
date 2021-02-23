#include <iostream>
#include <string>
using namespace std;

template<class T1, class T2>
class Person; // 这一步的目地是让下面的全局函数知道有Person类

// 通过全局函数打印Person的信息
// 全局函数在类外实现
template<class T1, class T2>
void printPerson2(Person<T1, T2> &p)
{cout << "Name: " << p.m_name << ". Age: " << p.m_age << endl;}

template<class T1, class T2>
class Person
{
	// 全局函数的类内实现
	friend void printPerson(Person<T1, T2> &p)
	{cout << "Name: " << p.m_name << ". Age: " << p.m_age << endl;}

	// 全局函数的类外实现
	// 如果全局函数是类外实现，需要让编译器提前知道这个函数的存在
	// 要在类的在上方实现全局函数
	friend void printPerson2<>(Person<T1, T2> &p); // 加空模板列表
public:
	Person(T1 name, T2 age) {this->m_name = name; this->m_age = age;}
private:
	T1 m_name;
	T2 m_age;
};

void test1()
{
	Person<string, int> person("Tom", 19);
	printPerson(person);
	printPerson2<>(person);
}

int main()
{
	test1();
    return 0;
}
