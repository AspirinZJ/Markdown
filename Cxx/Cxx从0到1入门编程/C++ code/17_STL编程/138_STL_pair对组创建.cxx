//pair<type, type> p(value1, value2);
//pair<type, type> p = make_pair(value1, value2);
#include <iostream>
#include <string>

using namespace std;

int main()
{
	// 第一种方式创建
	pair<string, int> pr("Alice", 19);
	// p.first第一个数据，p.second第二个数据
	cout << "Name: " << pr.first << ". Age: " << pr.second << endl;

	// 第二种方式创建
	pair<string, int> pr2 = make_pair("Bob", 21);
	cout << "Name: " << pr2.first << ". Age: " << pr2.second << endl;

    return 0;
}
