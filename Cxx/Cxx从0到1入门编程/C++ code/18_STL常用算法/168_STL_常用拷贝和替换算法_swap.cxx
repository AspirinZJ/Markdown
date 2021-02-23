//功能：交换两个容器内元素, 两个容器要同种类型
//swap(container c1, container c2)`
//c1 c2容器
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void myPrint(const int &val) {cout << val << ' ';}

int main()
{
	vector<int> iVec1 = {1, 2, 3};
	vector<int> iVec2 = {4, 5, 6};
	swap(iVec1, iVec2);
	for_each(iVec1.begin(), iVec1.end(), myPrint); cout << endl;
	for_each(iVec2.begin(), iVec2.end(), myPrint); cout << endl;
	return 0;
}
