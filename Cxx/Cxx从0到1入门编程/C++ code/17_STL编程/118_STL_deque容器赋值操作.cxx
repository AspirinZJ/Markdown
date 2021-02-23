//deque &operator=(const deque &deq); // 重载=操作符`
//assign(beg, end); // 将[beg, end)区间中的数据拷贝赋值给本身`
//assign(n, elem); 将n个elem赋值给本身`
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
	for (int i = 0; i < 10; ++i) {d1.push_back(i);}
	printDeque(d1);

	// 1. operator=重载赋值
	deque<int> d2 = d1;
	printDeque(d2);

	// 2. assgin(beg, end)
	deque<int> d3;
	d3.assign(d1.begin()+1, d1.end()-1);
	printDeque(d3);

	// 3. assgin(n, elem)
	deque<int> d4;
	d4.assign(5, 100);
	printDeque(d4);

	return 0;
}
