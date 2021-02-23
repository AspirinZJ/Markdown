//set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dst)`
//注意：两个集合必须是有序序列
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class CMyPrint
{
public:
	void operator()(const int &val) {cout << val << ' ';}
};

int main()
{
	vector<int> iVec1 = {1, 2, 3, 4, 5};
	vector<int> iVec2 = {4, 5, 6};
	vector<int> iVecDst1;
	vector<int> iVecDst2;
	// 提前为目标容器分配空间
	iVecDst1.resize(iVec1.size());
	iVecDst2.resize(iVec2.size());

	vector<int>::iterator it1 = set_difference(iVec1.begin(), iVec1.end(), iVec2.begin(), iVec2.end(), iVecDst1.begin());
	vector<int>::iterator it2 = set_difference(iVec2.begin(), iVec2.end(), iVec1.begin(), iVec1.end(), iVecDst2.begin());

	cout << "iVec1 - iVec2: " << endl;
	for_each(iVecDst1.begin(), it1, CMyPrint()); cout << endl;
	cout << "iVec2 - iVec1: " << endl;
	for_each(iVecDst2.begin(), it2, CMyPrint()); cout << endl;

	return 0;
}
