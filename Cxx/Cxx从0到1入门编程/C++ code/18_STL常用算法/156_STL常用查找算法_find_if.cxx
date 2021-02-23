//find_if(iterator beg, iterator end, _Pred); `
//按值查找元素，找到返回指定位置的迭代器，找不到返回结束迭代器.end()
//beg开始迭代器
//end结束迭代器
//Pred函数或者谓词(返回bool类型的仿函数)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class CMyCompareFive
{
public:
	bool operator()(const int &v1) const
	{ return (v1 == 5); }
};

class CPerson
{
public:
	CPerson(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	string m_name;
	int m_age;
};

class CAgeGreater20
{
public:
	bool operator()(const CPerson &person) const
	{ return person.m_age > 20; }
};

int main()
{
	// 按条件查找内置数据类型
	vector<int> iVec;
	for (int i = 0; i < 10; i++) { iVec.push_back(i); }

	vector<int>::iterator iit = find_if(iVec.begin(), iVec.end(), CMyCompareFive()); // 查找有没有5

	if (iVec.end() != iit) { cout << "Found 5." << endl; }
	else { cout << "Didn't find 5." << endl; }

	// 按条件查找自定义数据类型
	vector <CPerson> personVec;
	personVec.push_back(CPerson("Alice", 19));
	personVec.push_back(CPerson("Bob", 23));
	personVec.push_back(CPerson("Charlie", 23));
	// 查找容器中年龄大于20的人员
	vector<CPerson>::iterator pit = find_if(personVec.begin(), personVec.end(), CAgeGreater20());

	if (personVec.end() != pit)
	{
		cout << "Found person whose age is greater than 20." << endl;
		cout << pit->m_name << ' ' << pit->m_age << endl;
	}
	else { cout << "Cannot find such person. " << endl; }

	return 0;
}
