//区别：
//set不可以插入重复数据，而multiset可以
//set插入数据的同时会返回插入结果，表示插入是否成功
// multiset不会检测数据，因此可以插入重复数据
#include <iostream>
#include <set>

using namespace std;

int main()
{
	// *******set**************
	set<int> st1 = {34, 64, 234, 52, 27};
	// set的insert函数返回一个pair<iterator, bool>, 第一个是插入的迭代器，第二个表示是否插入成功
	pair<set<int>::iterator, bool> ret = st1.insert(190);
	if (ret.second) // 如果为真，说明插入成功
	{ cout << "Insert successfully." << endl; }
	else { cout << "Failed to insert." << endl; }

	ret = st1.insert(190);
	if (ret.second) // 如果为真，说明插入成功
	{ cout << "Insert successfully." << endl; }
	else { cout << "Failed to insert." << endl; } // 不允许插入重复数据

	// *******multiset**************
	multiset<int> mst = {10, 10, 10};
	// multiset的insert函数返回一个迭代器，不会检查数据
	multiset<int>::iterator mit = mst.insert(10);

	for (multiset<int>::const_iterator cit = mst.begin(); cit != mst.end(); ++cit) { cout << *cit << ' '; }
	cout << endl;

	return 0;
}
