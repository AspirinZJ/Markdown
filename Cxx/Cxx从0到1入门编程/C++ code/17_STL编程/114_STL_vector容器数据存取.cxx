// at(int idx); // 返回索引idx所指的数据`
// operator[]; 重载了[]，通过[]访问`
// front() 返回容器中第一个数据元素`
// back() 返回容器中最后一个数据元素`
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++) { v1.push_back(i); }

	// 利用[]访问vector中的元素
	for (int i = 0; i< 10; i++) {cout << v1[i] << ' ';}
	cout << endl;

	// 利用at成员函数访问
	for (int i = 0; i< v1.size(); i++) {cout << v1.at(i) << ' ';}
	cout << endl;

	// 利用front()函数获取第一个元素
	cout << "The first element: " << v1.front() << endl;
	// 利用back()函数获取最后一个元素
	cout << "The last element: " << v1.back() << endl;

	return 0;
}
