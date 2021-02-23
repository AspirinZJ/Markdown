#include <iostream>
#include <vector>

using namespace std;

void printVec(vector<int> &vec)
{
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{cout << *it << ' ';}
	cout << endl;
}

int main()
{
	vector<int> v1;
	for (int i = 0; i < 5; i++)
	{v1.push_back(i);}
	printVec(v1);

	// empty()函数, 1空， 0非空
	cout << v1.empty() << endl;
	cout << "Capacity of v1: " << v1.capacity() << endl; // capacity()
	cout << "Size of v1: " << v1.size() << endl; // size()

	// 重新指定大小resize()
	v1.resize(10); // 如果重新指定的比原来的长，用默认值填充剩余的位置
	printVec(v1);
	v1.resize(15, 100); // 指定resize函数默认的填充值
	printVec(v1);
	v1.resize(3);
	printVec(v1); // 如果重新指定的比原来短了，超出的部分会被删除

    return 0;
}
