//adjacent_find(iterator beg, iterator end);`
//查找相邻重复元素，返回相邻重复元素的第一个元素位置的迭代器，找不到返回结束迭代器.end()
//beg 开始迭代器
//end  结束迭代器
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> vec = {1, 21234, 3, 1223, 1, 3, 3};

	vector<int>::iterator it = adjacent_find(vec.begin(), vec.end());

	if (vec.end() != it) { cout << "Found: " << *it << endl; }
	else { cout << "Cannot find." << endl; }

	return 0;
}
