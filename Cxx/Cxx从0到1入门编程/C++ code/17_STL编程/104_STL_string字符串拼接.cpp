// string &operator+=(const char *str);`
// string &operator+=(const char c);`
// string &operator+=(const string &str);`
// string &append(const char *s);`
// string &append(const char *s, int n);\\ 将字符串s的前n个字符拼接到当前字符串尾`
// string &append(const string &s);`
// string &append(const string &s, int pos, int n); // 字符串s中从pos开始的n个字符拼接到当前字符串尾`
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str1("Hell");
	str1 += "o ";
	cout << str1 << endl;

	str1 += 'W';
	cout << str1 << endl;

	string str2 = "or";
	str1 += str2;
	cout << str1 << endl;

	str1.append("ld");
	cout << str1 << endl;

	str1.append(". Hello World.", 5);
	cout << str1 << endl;

	string str3 = "lo World.";
	str1.append(str3);
	cout << str1 << endl;

	str1.append(str3, 3, 6);
	cout << str1 << endl;

	return 0;
}