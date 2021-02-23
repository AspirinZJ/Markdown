#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str1; // 默认构造
	cout << str1 << endl;

	const char *str = "Hello World."; // c语言风格字符串
	string str2(str); // 使用c语言字符串初始化
	cout << str2 << endl;

	string str3(str2); // 使用c语言字符串初始化
	cout << str3 << endl;

	string str4(10, 'a');
	cout << str4 << endl;

	return 0;
}
