//bool binary_search(iterator beg, iterator end, value)`
//查找指定的元素，找到返回true，否则反狐false
//注意： 在无序序列中不能使用此函数
//beg开始迭代器
//end结束迭代器
//value查找的元素
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> vec;
	for (int i = 0; i < 10; i++ ) {vec.push_back(i);}

	// 查找容器中是否有9
	// 注意，容器必须是一个有序序列
	bool ret = binary_search(vec.begin(), vec.end(), 9);
	cout << "ret: " << ret << endl;

	vec.push_back(2); // 如果是无序序列，结果未知
	ret = binary_search(vec.begin(), vec.end(), 9);
	cout << "ret: " << ret << endl;

	return 0;
}
