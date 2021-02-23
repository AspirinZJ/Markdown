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
	vector<int> iVecTarget;
	iVecTarget.resize(iVec1.size() + iVec2.size()); // 提前开辟空间，最特殊情况下两个容器的size相加
	vector<int>::iterator itEnd = set_union(iVec1.begin(), iVec1.end(), iVec2.begin(), iVec2.end(), iVecTarget.begin());
	for_each(iVecTarget.begin(), iVecTarget.end(), CMyPrint()); cout << endl; // 错误
	for_each(iVecTarget.begin(), itEnd, CMyPrint()); cout << endl; // 正确，利用set_union函数返回的迭代器做为结束

    return 0;
}
