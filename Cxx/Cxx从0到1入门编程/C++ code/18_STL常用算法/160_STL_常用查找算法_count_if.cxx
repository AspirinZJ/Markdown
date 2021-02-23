/*
count_if(iterator beg, iterator end, _Pred)`
按条件统计元素出现的次数
beg 开始迭代器
end 结束迭代器
_Pred谓词
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CGreaterThan20
{
public:
	bool operator()(const int &val) const { return val > 20; }
};


class CPerson
{
public:
	CPerson(string name, int age) {this->m_name = name; this->m_age = age;}
	string m_name;
	int m_age;
};

class CAgeGreaterThan20
{
public:
	bool operator()(const CPerson &person) { return person.m_age > 20;}
};

int main()
{
	// 统计内置数据类型
	vector<int> intVec = {1, 3, 5, 21, 12};
	int num = count_if(intVec.begin(), intVec.end(), CGreaterThan20()); // 第三个参数是谓词
	cout << "num: " << num << endl;
	// 统计自定义数据类型
	vector<CPerson> personVec;
	personVec.push_back(CPerson("Alice", 10));
	personVec.push_back(CPerson("Bob", 20));
	personVec.push_back(CPerson("Charlie", 23));
	personVec.push_back(CPerson("David", 23));

	num = count_if(personVec.begin(), personVec.end(), CAgeGreaterThan20());
	cout << "num: "<< num << endl;

	return 0;
}
