// set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator  dst)`
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void myPrint(const int &val) {cout << val << ' ';}

int main()
{
	vector<int> iVec1 = {1, 2, 3, 4, 5};
	vector<int> iVec2 = {3, 4, 5, 6};
	vector<int> iVecDst;
	// 需要为目标容器提前开辟空间
	iVecDst.resize(min(iVec1.size(), iVec2.size())); // 开辟空间取小容器的size

	// set_intersection返回交集的结束迭代器
	vector<int>::iterator itEnd = set_intersection(iVec1.begin(), iVec1.end(), iVec2.begin(), iVec2.end(), iVecDst.begin());
	for_each(iVecDst.begin(), itEnd, myPrint);

    return 0;
}
