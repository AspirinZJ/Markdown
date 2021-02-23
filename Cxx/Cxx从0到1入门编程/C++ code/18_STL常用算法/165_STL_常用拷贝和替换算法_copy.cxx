//copy(iterator beg, iterator end, iterator dst)`
// beg 开始迭代器
// end 结束迭代器
//dst 目标容器起始迭代器
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void myPrint(int val)
{ cout << val << ' '; }

int main()
{
	vector<int> iVec1 = {1, 2, 3, 4, 5};
	vector<int> iVec2;
	iVec2.resize(iVec1.size());
	copy(iVec1.begin(), iVec1.end(), iVec2.begin());
	for_each(iVec2.begin(), iVec2.end(), myPrint);
	cout << endl;
	return 0;
}
