// size(); // 返回容器中元素个数`
// empty();`
// resize(num); // 重新指定容器的长度为num，若容器变长，则以默认值填充新位置，若容器便端，则末尾超过容器长度的元素被删除`
// resize(num, elem); // 重新指定容器的长度为num，若容器变长，则以elem填充新位置，若容器便端，则末尾超过容器长度的元素被删除`
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
	list<int> lst1;
	lst1.push_back(1);
	lst1.push_back(2);
	lst1.push_back(3);
	lst1.push_back(4);
	printList(lst1);
	cout << "list.empty(): " << lst1.empty() << endl;
	cout << "list size: " << lst1.size() << endl;

	lst1.resize(10);
	printList(lst1);

	lst1.resize(20, 666);
	printList(lst1);

	lst1.resize(3);
	printList(lst1);

	return 0;
}
