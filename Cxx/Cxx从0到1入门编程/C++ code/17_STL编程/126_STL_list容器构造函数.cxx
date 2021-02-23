// list<T> lst; // 默认构造`
// list(beg, end); // 构造函数将[beg, end)区间中的元素拷贝给本身`
// list(n, elem); // 构造函数将n个elem拷贝给本身`
// list(const list &lst); // 拷贝构造`
#include <iostream>
#include <list>

using namespace std;

void printList(const list<int> &lst)
{
	for (list<int>::const_iterator cit = lst.begin(); cit != lst.end(); ++cit) { cout << *cit << ' '; }
	cout << endl;
}

int main()
{
	list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	printList(lst);

	// 利用区间构造函数
	list<int> lst2(lst.begin(), lst.end());
	printList(lst2);

	// 拷贝构造
	list<int> lst3(lst2);
	printList(lst3);

	// n个elem构造
	list<int> lst4(5, 100);
	printList(lst4);
	return 0;
}
