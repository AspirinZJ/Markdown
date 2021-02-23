//accumulate(iterator beg, iterator end, value)`
//beg开始迭代器
//end结束迭代器
//value 起始值
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
	vector<int> iVec = {1, 2, 3};
	int ret = accumulate(iVec.begin(), iVec.end(), 10); // 参数3： 起始累加值
	cout << ret << endl;

	return 0;
}
