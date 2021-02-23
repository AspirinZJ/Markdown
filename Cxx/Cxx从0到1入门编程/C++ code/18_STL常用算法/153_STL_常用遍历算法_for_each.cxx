/*
for_each(iterator beg, iterator end, _func);`
beg, 开始迭代器
end， 结束迭代器
_func，函数或者函数对象
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 普通函数
void print1(int val)
{cout << val << ' ' ;}

// 仿函数
class CPrint2
{
public:
	void operator()(int val) {cout << val << ' ';}
};

int main()
{
	vector<int> vec;
	for (int i = 0; i < 10; i++) { vec.push_back(i); }
	// 遍历容器
	for_each(vec.begin(), vec.end(), print1); // 普通函数遍历
	cout << endl;

	for_each(vec.begin(), vec.end(), CPrint2()); // 仿函数遍历
	cout << endl;

	return 0;
}
