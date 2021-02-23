// assign(beg, end); //将[beg, end)区间中的元素赋值给本身 `
// assign(n, elem);`
// list &operator=(const list &lst); // 重载=运算符`
// swap(lst); //将lst与本身交换`
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
	list<int> lst1 = {1, 2, 3, 4};
	printList(lst1);

	list<int> lst2 = lst1; // 重载=
	printList(lst2);

	list<int> lst3;
	lst3.assign(lst2.begin(), lst2.end()); // assign
	printList(lst3);

	list<int> lst4;
	lst4.assign(10, 5);
	printList(lst4);

	// 交换swap
	lst4.swap(lst1);
	printList(lst1);
	printList(lst4);

	return 0;
}
