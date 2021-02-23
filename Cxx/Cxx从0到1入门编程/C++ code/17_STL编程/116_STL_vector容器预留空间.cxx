// 功能：减少vector在动态扩展容量时的扩展次数
// reserve(int len); // 容器预留len个元素长度，预留位置不初始化，元素不可访问`
#include <iostream>
#include <vector>

using namespace std;


int main()
{
	vector<int> v;
	// **************预留空间*************
	// v.reserve(100000); // 如果预留空间，在达到容量前不会动态扩展

	int changeNum; // 统计开辟次数，即动态扩展次数
	int *p = nullptr;

	for (int i = 0; i < 100000; ++i)
	{
		v.push_back(i);
		if (p != &v[0]) // 如果指针不指向首地址, 表示更换了一次内存，即动态扩展了一次
		{
			p = &v[0]; // 指向首地址
			changeNum++;
		}
	}
	cout << "changeNum: " << changeNum << endl;
	return 0;
}
