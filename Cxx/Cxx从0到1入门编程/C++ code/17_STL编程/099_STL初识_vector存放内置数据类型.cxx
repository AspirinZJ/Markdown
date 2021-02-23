// vector容器存放内置数据类型
#include <iostream>
#include <vector> // 包含头文件
#include <algorithm> // 标准算法头文件
using namespace std;

void myPrint(int val)
{cout << val << endl;}

void test1()
{
	vector<int>	vec;

	vec.push_back(10); // 尾插数据
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);

	// 通过迭代器访问容器中的数据
	vector<int>::iterator itBegin = vec.begin(); // 起始迭代器，指向容器中第一个元素
	vector<int>::iterator itEnd = vec.end(); // 结束迭代器，指向容器中最后一个元素的下一个位置

	// 第一种遍历方式
	while (itBegin != itEnd)
	{
		cout << *itBegin << endl; // 将迭代器看作指针，解引用
		itBegin++;
	}

	// 第二种遍历方式
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{cout << *it << endl;}

	// 第三种遍历方式, 利用STL中提供的遍历算法
	// 利用STL中提供的算法需要包含算法头文件algorithm
	for_each(vec.begin(), vec.end(), myPrint);
}

int main()
{
	test1();
    return 0;
}
