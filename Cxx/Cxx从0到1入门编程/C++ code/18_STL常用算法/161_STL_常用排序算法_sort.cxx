#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

void myPrint(int val) {cout << val << ' ';}

int main()
{
	vector<int> intVec = {23, 234, 1, 345, 2, 1, 1};
	sort(intVec.begin(), intVec.end()); // 默认升序排序
	for_each(intVec.begin(), intVec.end(), myPrint); cout << endl;

	// 改为降序排序
	sort(intVec.begin(), intVec.end(), greater<int>());
	for_each(intVec.begin(), intVec.end(), myPrint); cout << endl;

	return 0;
}
