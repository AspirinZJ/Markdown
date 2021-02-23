//两端插入操作
//push_back();//尾插`
//push_front(); // 头插`
//pop_back(); // 尾删`
//pop_front(); // 头删`
//
//指定位置操作：
//insert(pos, elem); // 在pos位置插入elem元素，返回新数据的位置`
//insert(pos, n, elem); // 在pos位置插入n个elem，无返回值`
//insert(pos, beg, end); // 在pos位置插入[beg, end)区间的数据，无返回值`
//clear(); // 清空容器内的数据`
//erase(beg, end); // 删除[beg, end)区间的数据，返回下一个数据的位置`
//erase(pos); // 删除pos位置的数据， 返回下一个数据的位置`
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
	// 尾插
	d1.push_back(10);
	d1.push_back(20);
	// 头插
	d1.push_front(5);
	d1.push_front(7);
	printDeque(d1);
	// 尾删
	d1.pop_back();
	d1.pop_front();
	printDeque(d1);

	// 指定容器操作
	deque<int> d2 = {10, 20, 30, 40};
	d2.insert(d2.begin() + 1, 66);
	printDeque(d2);
	d2.insert(d2.begin(), 2, 55);
	printDeque(d2);
	// 按照区间插入
	d2.insert(d2.begin(), d1.begin(), d1.end());
	printDeque(d2);
	// 删除
	deque<int>::iterator it = d2.begin();
	++it;
	d2.erase(it, d2.end()-2);
	printDeque(d2);
	d2.erase(it);
	printDeque(d2);
	d2.clear();
	printDeque(d2);

	return 0;
}
