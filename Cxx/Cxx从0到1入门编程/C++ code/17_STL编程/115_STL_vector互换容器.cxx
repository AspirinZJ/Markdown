// vector互换容器
#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> &vec)
{
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{cout << (*it) << ' ';}
	cout << endl;
}

int main()
{
	cout << "Before swapping: " << endl;
	vector<int> v1;
	for (int i = 0; i < 10; i++) {v1.push_back(i);}
	printVector(v1);

	vector<int> v2;
	for (int i = 10; i >= 0; --i) {v2.push_back(i);}
	printVector(v2);

	// swap
	v1.swap(v2);
	printVector(v1);
	printVector(v2);


	//实际用途，巧用swap可以收缩内存空间
	vector<int> v;
	for (int i = 0; i < 100000; ++i) {v.push_back(i);}
	cout << "The capacity of v: " << v.capacity() << endl;
	cout << "The size of v: " << v.size() << endl;

	v.resize(3); // 重新指定大小
	cout << "The capacity of v: " << v.capacity() << endl; // 虽然改变了size为3,容量仍是13万,造成了空间浪费
	cout << "The size of v: " << v.size() << endl;

	// 巧用swap收缩内存
	vector<int>(v).swap(v); // 收缩了内存
	cout << "The capacity of v: " << v.capacity() << endl; // 虽然改变了size为3,容量仍是13万,造成了空间浪费
	cout << "The size of v: " << v.size() << endl;
	// 解释：
	// vector<int>(v)调用了拷贝构造函数创建了一个匿名对象，这个对象以v为原型，size和capacity都是3
	// vector<int>(v).swap(v) 把刚创建的匿名对象和v交换，此时v的size和capacity都是3，匿名对象size是3,capacity是13万多
	// 交换之后，这一句运行结束后，匿名对象被释放，达到了收缩内存的目的

	return 0;
}
