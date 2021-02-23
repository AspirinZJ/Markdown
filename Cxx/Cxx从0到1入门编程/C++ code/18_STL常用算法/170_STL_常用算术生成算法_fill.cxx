//功能：向容器区间内填充指定的元素
//fill(iterator beg, iterator end, value)`
#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
#include <algorithm>

using namespace std;

void myPrint(const int &val) {cout << val << ' ';}

int main()
{
	vector<int> iVec;
	iVec.resize(10); // 默认以0填充
	fill(iVec.begin(), iVec.end(), 10); // 重新以0填充
	for_each(iVec.begin(), iVec.end(), myPrint);
    return 0;
}
