//size();`
//empty();`
//swap(st); //交换两个集合容器`
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
	set<int> st1 = {1, 4563, 23, 3452, 435};
	st1.insert(443); // insert插入
	printSet(st1);

	cout << "Set.empty(): " << st1.empty() << endl; // empty() member function
	cout << "Set.size(): " << st1.size() << endl; // size() member function

	set<int> st2;
	st2.insert(56);
	st2.swap(st1);
	printSet(st1);
	printSet(st2);

    return 0;
}
