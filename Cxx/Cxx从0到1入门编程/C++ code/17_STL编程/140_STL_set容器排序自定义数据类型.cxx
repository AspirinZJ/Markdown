#include <iostream>
#include <set>
#include <string>

using namespace std;

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

class CMyCompare
{
public:
	bool operator()(const CPerson &p1, const CPerson &p2) const // 按照年龄降序
	{ return p1.m_age > p2.m_age; }
};

int main()
{
	// 自定义的数据类型一定要指定排序规则
	// 利用仿函数指定函数规则
	set <CPerson, CMyCompare> personSt; // 按照CMyCompare中指定的规则排列
	personSt.insert(CPerson("Alice", 49));
	personSt.insert(CPerson("Bob", 29));
	personSt.insert(CPerson("Charlie", 89));
	personSt.insert(CPerson("David", 79));

	for (set<CPerson, CMyCompare>::const_iterator cit = personSt.begin(); cit != personSt.end(); ++cit)
	{
		cout << "Name: " << cit->m_name << ". Age: " << (*cit).m_age << endl;
	}

	return 0;
}
