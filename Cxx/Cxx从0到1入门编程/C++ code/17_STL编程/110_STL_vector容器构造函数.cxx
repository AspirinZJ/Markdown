// vector<T> v; // 采用模板类实现，默认构造函数`
// vector(v.begin(), v.end()); // 将v[begin(), end()]区间中的元素拷贝给本身`
// vector(n, elem); // 构造函数将n个elem拷贝给本身`
// vector(const vector &vec); // 拷贝构造`
#include <iostream>
#include <vector>

using namespace std;

void printVec(vector<int> intVec)
{
	for (vector<int>::iterator it = intVec.begin(); it != intVec.end(); it++)
	{cout << (*it) << ' ';}
	cout << endl;
}

int main()
{
	vector<int> intVec1; // 默认构造
	for (int i = 0; i < 5; i++)
	{intVec1.push_back(i);}
	printVec(intVec1);

	// 通过去区间的方式进行构造
	vector<int> intVec2(intVec1.begin(), intVec1.end());
	printVec(intVec2);

	// 通过n个element构造
	vector<int> intVec3(5, 10);
	printVec(intVec3);

	// 拷贝构造
	vector<int> intVec4(intVec3);
	printVec(intVec4);

    return 0;
}
