//count(iterator beg, iterator end, value)`
//统计元素出现次数
//beg开始迭代器
//end结束迭代器
//value统计的元素
#include <iostream>
#include <vector>
#include <algorithm>
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

	bool operator==(const CPerson &person) const {return (this->m_age == person.m_age);} // 年龄相同

	string m_name;
	int m_age;
};

int main()
{
	// 统计内置数据类型
	vector<int> iVec = {1234, 1, 1, 34, 432, 1, 234, 12, 341, 3, 1};
	int num = std::count(iVec.begin(), iVec.end(), 1);
	cout << "The number of 1 is : " << num << endl;

	// 统计自定义数据类型
	vector<CPerson> personVec;
	personVec.push_back(CPerson("Alice", 19));
	personVec.push_back(CPerson("Bob", 22));
	personVec.push_back(CPerson("Charlie", 19));
	int num2 = count(personVec.begin(), personVec.end(), CPerson("Alice", 19)); //统计年龄为19的人数
	cout << "The number : " << num2 << endl;

	return 0;
}
