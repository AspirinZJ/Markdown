#include <iostream>
#include <string>
#include <utility>
#include "myArray.hpp"

using namespace std;

// 自定义数据类型
class Person
{
public:
	Person()
	= default;

	Person(string name, int age)
	{
		this->m_name = std::move(name);
		this->m_age = age;
	}

	string m_name;
	int m_age{};
};

void printIntArr(CMyArray<int> &arr)
{
	for (int i = 0; i < arr.getSize(); i++) { cout << arr[i] << endl; }
}

void test1()
{
	CMyArray<int> arr1(5);

	for (int i = 0; i < 5; i++) { arr1.pushBack(i); } // 利用尾插法向数组中插入数据
	printIntArr(arr1);

	cout << "Capacity of arr1: " << arr1.getCapacity() << endl;
	cout << "Size of arr1: " << arr1.getSize() << endl;

	CMyArray<int> arr2(arr1);
	printIntArr(arr2);
	arr2.popBack(); // 尾删法删除数据
	cout << "Capacity of arr2: " << arr2.getCapacity() << endl;
	cout << "Size of arr2: " << arr2.getSize() << endl;
}

void test2()
{
	// 测试自定义数据类型
	CMyArray<Person> personArr(10);

	Person p1("Alice", 19);
	Person p2("Charlie", 20);
	Person p3("Bob", 39);

	personArr.pushBack(p1);
	personArr.pushBack(p2);
	personArr.pushBack(p3);

	for (int i = 0; i < personArr.getSize(); i++)
	{cout << "The name of " << i << "th person: " << personArr[i].m_name << ". Age: " << personArr[i].m_age << endl;}
	cout << "personArr capacity: " << personArr.getCapacity() << endl;
	cout << "personArr size: " << personArr.getSize() << endl;
}

int main()
{
	test1();
	test2();
	return 0;
}
