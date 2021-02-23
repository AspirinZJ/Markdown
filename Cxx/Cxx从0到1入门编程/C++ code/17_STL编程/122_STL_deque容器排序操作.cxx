// sort(iterator begin, iterator end); // 对beg和end区间内元素进行排序`
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

void printDeque(const deque<int> &deq)
{
	for (deque<int>::const_iterator it = deq.begin(); it != deq.end(); ++it)
	{cout << (*it) << ' ';}
	cout << endl;
}

int main()
{
	deque<int> d1 = {34, 4356, 234, 4643, 234, 32423, 12};
	// 对于支持随机访问的迭代器的容器，都可以用sort算法直接对其进行排序
	sort(d1.begin(), d1.end()); // 排序
	printDeque(d1);

	return 0;
}
