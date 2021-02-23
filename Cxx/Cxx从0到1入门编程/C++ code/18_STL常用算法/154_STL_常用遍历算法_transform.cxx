/*
transform(iterator beg1, iterator end1, iterator beg2, _func)`
beg1源容器起始迭代器
end1源容器结束迭代器
beg2目标容器起始迭代器
_func函数或者函数对象
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class CTransform
{
public:
	int operator()(int v) { return v + 100;}
};

class CMyPrint
{
public:
	void operator()(int v) {cout << v << ' ';}
};

int main()
{
	vector<int> srcVec; // 源容器
	for (int i = 0; i < 10; i++) { srcVec.push_back(i); }

	vector<int> dstVec; // 目标容器

	// 目标容器搬运前需要开辟空间
	dstVec.resize(srcVec.size());
	transform(srcVec.begin(), srcVec.end(), dstVec.begin(), CTransform());
	for_each(dstVec.begin(), dstVec.end(), CMyPrint());
	cout << endl;

	return 0;
}
