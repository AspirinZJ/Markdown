//deque.empty(); // 判断容器是否为空`
//deque.size(); // 返回容器中元素的个数`
//deque.resize(num); // 重新指定容器的长度为num，若容器变长，则以默认值填充新位置，若容器便端，则末尾超过容器长度的元素被删除`
//deque.resize(num, elem); // 重新指定容器的长度为num，若容器变长，则以elem填充新位置，若容器便端，则末尾超过容器长度的元素被删除`

#include <iostream>
#include <deque>

using namespace std;

void printDeque(const deque<int> &deq)
{
	for (deque<int>::const_iterator it = deq.begin(); it != deq.end(); ++it)
	{cout << (*it) << ' ';}
	cout << endl;
}

int main()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++) {d1.push_back(i);}
	printDeque(d1);

	cout << "d1.empty: " << d1.empty() << endl; // empty()函数
	cout << "d1.size(): " << d1.size() << endl; // size()函数

	// 重新指定大小resize()
	d1.resize(15);
	printDeque(d1);
	d1.resize(20, 6);
	printDeque(d1);
	d1.resize(3);
	printDeque(d1);

	return 0;
}
