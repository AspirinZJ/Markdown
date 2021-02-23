//at(int idx); // 返回索引idx的所指的数据`
//operator[]; // 通过[]访问`
//front(); // 返回容器中第一个数据元素`
//back(); // 返回容器中最后以后一个数据元素`

#include <iostream>
#include <deque>

using namespace std;

int main()
{
	deque<int> d1 = {1, 2, 4, 5, 5};
	// 通过[]访问
	for (int i = 0; i < d1.size(); ++i) { cout << d1[i] << ' '; }
	cout << endl;
	// 通过at()访问
	for (int i = 0; i < d1.size(); ++i) { cout << d1.at(i) << ' '; }
	cout << endl;

	// front() back()
	cout << "d1.front(): " << d1.front() << ". d1.back(): " << d1.back() << endl;

	return 0;
}
