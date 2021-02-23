#include <iostream>
#include <vector>

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

void test1()
{
	vector <CPerson> personVec;

	CPerson p1("p1", 10);
	CPerson p2("p1", 20);
	CPerson p3("p1", 30);
	CPerson p4("p1", 40);
	CPerson p5("p1", 50);

	personVec.push_back(p1);
	personVec.push_back(p2);
	personVec.push_back(p3);
	personVec.push_back(p4);
	personVec.push_back(p5);

	// 遍历容器中的数据，方法1
	// it方法1,将之当作指针解引用*it
	for (vector<CPerson>::iterator it = personVec.begin(); it != personVec.end(); it++)
	{
		cout << "name: " << (*it).m_name << ". age: " << (*it).m_age << endl;
	}
	// it方法2,将之当作指针it->属性
	for (vector<CPerson>::iterator it = personVec.begin(); it != personVec.end(); it++)
	{
		cout << "name: " << (*it).m_name << ". age: " << (*it).m_age << endl;
	}

	// 遍历容器中的数据，方法2
}

// 存放自定义数据类型的指针
void test2()
{
	vector<CPerson*> pPersonVec;

	CPerson p1("p1", 10);
	CPerson p2("p1", 20);
	CPerson p3("p1", 30);
	CPerson p4("p1", 40);
	CPerson p5("p1", 50);

	pPersonVec.push_back(&p1);
	pPersonVec.push_back(&p2);
	pPersonVec.push_back(&p3);
	pPersonVec.push_back(&p4);
	pPersonVec.push_back(&p5);

	// 遍历容器
	for (vector<CPerson*>::iterator it = pPersonVec.begin(); it != pPersonVec.end(); it++)
	{cout << "Name: " << (*it)->m_name << ". Age: " << (*it)->m_age << endl;}

}


int main()
{
	// test1();
	test2();
	return 0;
}
