#include <iostream>
#include <vector>

using namespace std;

void printVec(vector<int> &vec)
{
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{cout << (*it) << ' ';}
	cout << endl;
}

int main()
{
	vector<int> v1;
	for (int i = 0; i < 5; i++)
	{v1.push_back(i);}
	printVec(v1);

	vector<int> v2;
	v2 = v1; // 重载=运算符
	printVec(v2);

	// assign赋值
	vector<int> v3;
	v3.assign(v1.begin(), v1.end());
	printVec(v3);

	// assign赋值
	vector<int> v4;
	v4.assign(5, 1);
	printVec(v4);

    return 0;
}