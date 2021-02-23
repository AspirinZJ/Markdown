#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class CMyCompare
{
public:
	bool operator()(int v1, int v2)
	{ return v1 > v2; } // 二元谓词
};

int main()
{
	vector<int> vec = {1, 4, 2, 5, 6, 3};
	sort(vec.begin(), vec.end()); // sort默认升序排序
	for (vector<int>::const_iterator cit = vec.begin(); cit != vec.end(); ++cit) { cout << *cit << ' '; }
	cout << endl;

	// 使用函数对象改变排序规则策略
	// 降序排序
	sort(vec.begin(), vec.end(), CMyCompare());
	for (vector<int>::const_iterator cit = vec.begin(); cit != vec.end(); ++cit) { cout << *cit << ' '; }
	cout << endl;

	return 0;
}
