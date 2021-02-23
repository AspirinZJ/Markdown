//merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dst)`
//beg1, end1, 容器1开始和结束迭代器
//beg2, end2, 容器2开始和结束迭代器
//dst目标容器开始迭代器
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

void myPrint(int val)
{ cout << val << ' '; }

int main()
{
	vector<int> iVec1;
	vector<int> iVec2;
	for (int i = 0; i < 5; i++)
	{
		iVec1.push_back(i);
		iVec2.push_back(i+1);
	}
	vector<int> iVecTarget;
	iVecTarget.resize(iVec1.size() + iVec2.size()); // * * 目标容器要提前分配空间


	merge(iVec1.begin(), iVec1.end(), iVec2.begin(), iVec2.end(), iVecTarget.begin());
	for_each(iVecTarget.begin(), iVecTarget.end(), myPrint);
	cout << endl;
	return 0;
}
