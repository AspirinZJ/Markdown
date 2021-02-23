//set<T> st; // 默认构造`
//set(const set &st); // 拷贝构造`
//set &operator=(const set &st); // 重载等号运算符`
#include <iostream>
#include <set> // set和multiset

using namespace std;

void printSet(const set<int> &st)
{
	for (set<int>::iterator it = st.begin(); it != st.end(); ++it)
	{cout << *it << ' ';}
	cout << endl;
}

int main()
{
	set<int> st1;

	// set只有insert方式插入
	// set容器特点：所有的元素在插入时会自动排序
	// set容器不允许插入重复的值，重复插入不会报错，但是会不起作用
	st1.insert(1);
	st1.insert(4);
	st1.insert(3);
	st1.insert(2);
	printSet(st1);

	// 拷贝构造
	set<int> st2(st1);
	printSet(st2);

	// 赋值
	set<int> st3;
	st3 = st1;
	printSet(st3);

    return 0;
}
