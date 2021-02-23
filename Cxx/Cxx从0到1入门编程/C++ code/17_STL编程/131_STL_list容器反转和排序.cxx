//reverse(); // 反转链表`
//sort(); // 链表排序`
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

void printList(const list<int> &lst)
{
	for (list<int>::const_iterator cit = lst.begin(); cit != lst.end(); ++cit)
	{cout << *cit << ' ';}
	cout << endl;
}

bool myCompare(int i1, int i2)
{
	// 降序， 就让第一个数大于第二个数
	return i1 > i2;
}

int main()
{
	list<int> lst1 = {1, 6, 7, 3, 5, 234, 54};
	printList(lst1);

	// 反转
	lst1.reverse();
	printList(lst1);

	// 排序
	// sort(lst1.begin(), lst1.end()); 不能用标准algorithm算法库中的sort(list)，因为所有不支持随机访问迭代器的容器，都不可以用标准的算法
	lst1.sort(); // 不支持随机访问迭代器的容器，内部会提供一些算法，如list中的sort()成员函数
	printList(lst1); // 默认升序排序
	// *********降序排序*************
	lst1.sort(myCompare);
	printList(lst1);

	return 0;
}
