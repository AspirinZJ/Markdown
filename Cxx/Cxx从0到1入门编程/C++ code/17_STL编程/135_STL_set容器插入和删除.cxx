//insert(elem); // 插入elem`
//clear(); // 清空容器`
//erase(pos); // 删除迭代器pos所指的元素，返回下一个元素的迭代器`
//erase(beg, end); // 删除区间[beg, end)的元素，返回下一个元素的迭代器`
//erase(elem); // 删除元素elem`
#include <iostream>
#include <set>

using namespace std;

void printSet(const set<int> &st)
{
	for (set<int>::const_iterator cit = st.begin(); cit != st.end(); ++cit)
	{cout << *cit << ' ';}
	cout << endl;
}

int main()
{
	set<int> st1;
	// insert()
	st1.insert(981);
	st1.insert(33);
	st1.insert(91);
	st1.insert(3);
	printSet(st1);

	// erase()
	set<int>::iterator it = st1.begin();	// 注意容器中第一个数据是3
	st1.erase(it); // 删除了3
	printSet(st1);
	st1.erase(981); // 删除指定数据
	printSet(st1);
	st1.erase(st1.begin(), st1.end()); // 删除区间元素
	printSet(st1);
	st1.clear(); // clear()
	printSet(st1);

    return 0;
}
