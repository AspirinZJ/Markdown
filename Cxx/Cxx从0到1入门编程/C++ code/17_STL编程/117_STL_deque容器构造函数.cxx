// deque<T> deqT; // 默认构造`
// deque(begin, end); // 构造函数将[begin, end)去见中的元素拷贝给本身`
// deque(n, elem); // 构造函数将n个elem拷贝给本身`
// deque(const deque &deq); // 拷贝构造`
#include <iostream>
#include <deque>

using namespace std;

void printDeque(const deque<int> &deq) // 加const防止修改deq的数据
{
	for (deque<int>::const_iterator it = deq.begin(); it != deq.end(); ++it) // const_iterator: 只读迭代器
	{
		cout << (*it) << ' ';
		// *it = i; // 会报错，因为it是一个只读迭代器
	}
	cout << endl;
}

int main()
{
	deque<int> d1;
	for (int i = 0; i < 10; ++i) { d1.push_back(i); }
	printDeque(d1);

	// 区间构造函数
	deque<int> d2(d1.begin(), d1.end());
	printDeque(d2);

	// n个elem
	deque<int> d3(10, 5);
	printDeque(d3);

	// 拷贝构造
	deque<int> d4(d3);
	printDeque(d4);

	return 0;
}
