// list对自定义数据类型排序
// 将Person类进行排序，属性有姓名，年龄，身高
// 按照年龄升序，如果年龄相同按照身高进行降序
#include <iostream>
#include <list>
#include <string>

using namespace std;

class CPerson
{
public:
	CPerson(string name, int age, float height)
	{
		this->m_name = name;
		this->m_age = age;
		this->m_height = height;
	}
	string m_name;
	int m_age;
	float m_height;
};

// ***************指定排序规则********************
bool myCompare(const CPerson &p1, const CPerson &p2)
{
	if (p1.m_age < p2.m_age) {return true;}
	else if(p1.m_age == p2.m_age)// 如果年龄相同，按照身高降序
	{return (p1.m_height > p2.m_height);}
	else{return false;}
}

int main()
{
	list<CPerson> personLst;
	personLst.push_back(CPerson("Alice", 12, 172.8));
	personLst.push_back(CPerson("Bob", 17, 165.1));
	personLst.push_back(CPerson("Charlie", 12, 185.2));
	personLst.push_back(CPerson("David", 19, 171.5));

	cout << "Before sorting: " << endl;
	for (list<CPerson>::const_iterator cit = personLst.begin(); cit != personLst.end(); ++cit)
	{cout << "Name: " << cit->m_name << ". Age: " << (*cit).m_age << ". Height: " << cit->m_height << endl;}

	cout << "After sorting: " << endl;
	personLst.sort(myCompare);
	for (list<CPerson>::const_iterator cit = personLst.begin(); cit != personLst.end(); ++cit)
	{cout << "Name: " << cit->m_name << ". Age: " << (*cit).m_age << ". Height: " << cit->m_height << endl;}

	return 0;
}
