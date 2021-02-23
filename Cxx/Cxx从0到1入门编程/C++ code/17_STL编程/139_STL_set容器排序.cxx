//set容器默认升序排序
//利用仿函数，可以改变排序规则
#include <iostream>
#include <set>

using namespace std;

class CMyCompare
{
public:
	// 重载()运算符
	bool operator()(const int &v1, const int &v2) const
	{ return v1 > v2; } // 降序排序
};

void printSet(const set<int> &st)
{
	for (set<int>::const_iterator cit = st.begin(); cit != st.end(); ++cit) { cout << *cit << ' '; }
	cout << endl;
}

// 重载printSet()
void printSet(const set<int, CMyCompare> &st)
{
	for (set<int, CMyCompare>::const_iterator cit = st.begin(); cit != st.end(); ++cit) { cout << *cit << ' '; }
	cout << endl;
}


int main()
{
	set<int> st1 = {345, 3, 27, 254, 567675, 46}; // 默认升序排序
	printSet(st1);

	// set容器在创建时就要指定排序规则
	// 指定规则从大到小
	set<int, CMyCompare> st2;
	st2.insert(53);
	st2.insert(13);
	st2.insert(63);
	printSet(st2);

	return 0;
}
