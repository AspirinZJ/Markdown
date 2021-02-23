#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str = "hello";

	// 1. 通过[]访问单个字符
	for (int i = 0; i < str.size(); i++)
	{cout << str[i] << endl;}

	// 2. 通过at访问单个字符
	for (int i = 0; i < str.size(); i++)
	{cout << str.at(i) << endl;}

	str[0] = 'x';
	str.at(1) = 'x';
	cout << str << endl;

    return 0;
}
