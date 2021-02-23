/*
template<class T> bool logical_and<T>//与`
template<class T> bool logical_or<T>//或`
template<class T> bool logical_not<T>//非`
*/
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<bool> boolVec = {true, false, false, false};
	for (vector<bool>::const_iterator cit = boolVec.begin(); cit != boolVec.end(); ++cit)
	{ cout << *cit << ' ';}
	cout << endl;

	// 利用逻辑非，将容器boolVec搬运到容器boolVec2中，并执行取反操作
	vector<bool> boolVec2;
	boolVec2.resize(boolVec.size()); // 准备空间, 否则无法搬运

	transform(boolVec.begin(), boolVec.end(), boolVec2.begin(), logical_not<bool>()); //搬运数据
	for (vector<bool>::const_iterator cit = boolVec2.begin(); cit != boolVec2.end(); ++cit)
	{ cout << *cit << ' ';}
	cout << endl;

	return 0;
}
