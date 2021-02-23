#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str = "Hello";
	// 插入
	str.insert(1, "xx");
	cout << str << endl;

	// 删除
	str.erase(1, 2);
	cout << str << endl;

	return 0;
}
