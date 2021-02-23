/*
find(iterator beg, iterator end, value)`
按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器
beg开始迭代器
end结束迭代器
value按值查找的元素
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class CPerson
{
public:
	CPerson(string name, int age) {this->m_name =name; this->m_age = age;}
	bool operator==(const CPerson &person) const
	{
		if (person.m_name == this->m_name && person.m_age == this->m_age) {return true;}
		else {return false;}
	}
	string m_name;
	int m_age;
};

int main()
{
	// 查找内置数据类型
	vector<int> vec;
	for (int i = 0; i < 10; i++) { vec.push_back(i); }
	//查找容器中是否有5
	vector<int>::iterator retIt = find(vec.begin(), vec.end(), 5);

	if (vec.end() != retIt) { cout << "Found element : " << *retIt << endl; }
	else { cout << "Cannot find element." << endl; }


	// 查找自定义数据类型
	vector<CPerson> personVec;
	personVec.push_back(CPerson("Alice", 19));
	personVec.push_back(CPerson("Bob", 25));
	personVec.push_back(CPerson("Charlie", 31));

	// 需要重载==运算符
	vector<CPerson>::iterator pIt = find(personVec.begin(), personVec.end(), CPerson("Alice", 19));

	 if (personVec.end() != pIt) {cout << "Found : " << pIt->m_name << " ." << (*pIt).m_age << endl;}
	 else {cout << "Didn't Find such person." << endl;}

	return 0;
}
