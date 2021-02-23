//push_back(elem); // 尾插`
//pop_back(); // 删除容器中最后一个元素`
//push_front(elem); // 头插`
//pop_front(); // 删除容器中头一个元素`
//insert(pos, elem); // 在pos位置插入elem`
//insert(pos, n, elem); // 在pos插入n个elem`
//insert(pos, beg, end); // 在pos插入[beg, end)区间的数据`
//clear(); // 清空容器`
//erase(beg, end); // 删除[beg, end)区间的数据`
//erase(pos); // 删除pos处数据`
//remove(elem); // 删除容器中所有与elem值匹配的元素`
#include <iostream>
#include <list>

using namespace std;

void printList(const list<int> &lst)
{
	for (list<int>::const_iterator cit = lst.begin(); cit != lst.end(); ++cit)
	{cout << *cit << ' ';}
	cout << endl;
}

int main()
{
	list<int> lst = {1, 2, 3, 4};
	// 尾插
	lst.push_back(5);
	// 头插
	lst.push_front(0);
	printList(lst);

	// 尾删
	lst.pop_back();
	// 头删
	lst.pop_front();
	printList(lst);

	// insert()
	list<int>::iterator it = lst.begin();
	++it;
	lst.insert(it, 666);
	printList(lst);

	// 删除
	it = lst.begin();
	lst.erase(it);
	printList(lst);

	// remove删除匹配的值
	lst.remove(3);
	printList(lst);
	lst.push_back(10);
	lst.push_back(10);
	lst.push_back(10);
	lst.push_back(10);
	lst.remove(10);
	printList(lst); // remove会删除所有匹配的元素
	lst.remove(1000); // 如果不存在就不会进行操作

	lst.clear();
	printList(lst);

	return 0;
}
