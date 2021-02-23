//find(key); // 查找key是否存在，若存在，返回该key的元素的迭代器;若不存在，返回set.end();`
//count(key); // 统计key的元素个数`
#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<int> st1 = {324, 23453, 23456, 234, 456, 5674};
	// find()查找
	set<int>::iterator it = st1.find(234); // find()返回迭代器
	if (st1.end() != it) { cout << "Found element!" << endl; }
	else { cout << "Didn't find element." << endl; }

	// count() 统计
	int num = st1.count(456); // count() 对于set而言，只能返回0或1
	cout << "The number of 456: " << num << endl;

	return 0;
}
