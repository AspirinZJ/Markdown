/*
template<class T> bool equal_to<T>;//等于`
template<class T> bool not_equal_to<T>;//不等于`
template<class T> bool greater<T>;//大于`
template<class T> bool greater_equal<T>;//大于等于`
template<class T> bool less<T>;//小于`
template<class T> bool less_equal<T>;//小于等于`
*/
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(const vector<int> &vec)
{
	for (vector<int>::const_iterator cit = vec.begin(); cit != vec.end(); ++cit) { cout << *cit << ' '; }
	cout << endl;
}

class CMyCompare
{
public:
	bool operator()(int v1, int v2) const
	{ return v1 > v2; } // 降序排序
};

int main()
{
	vector<int> iVec = {1, 3, 4, 2, 5};
	printVector(iVec);
	// sort(iVec.begin(), iVec.end(), CMyCompare());
	// greater<int>() 内建函数对象
	sort(iVec.begin(), iVec.end(), greater<int>()); // 第三个参数创建了一个匿名对象，之后传入
	printVector(iVec);


	return 0;
}
