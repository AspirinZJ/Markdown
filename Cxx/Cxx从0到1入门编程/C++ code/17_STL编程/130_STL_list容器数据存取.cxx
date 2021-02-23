/*
front(); // 返回第一个元素`
back(); // 返回最后一个元素`
*/
#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> lst1 = {1, 2, 3, 4};
	cout << "The first element in lst1: " << lst1.front() << endl;
	cout << "The last element in lst1: " << lst1.back() << endl;

	// list迭代器不支持随机访问
	list<int>::iterator it = lst1.begin();
	++it;
	--it; // 既能++，也能--，说明迭代器是双向的
	// it = it + 1; // 会报错，因为list迭代器不支持随机访问

    return 0;
}
