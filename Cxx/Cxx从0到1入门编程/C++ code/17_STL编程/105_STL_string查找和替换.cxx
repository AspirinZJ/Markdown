// int find(const string &str, int pos=0) const; // 查找str第一次出现位置，从pos开始查找`
// int find(const char *s, int pos = 0) const;`
// int find(const char *s, int pos, int n) const; // 从pos位置查找s的前n个字符出现的第一次位置`
// int find(const char c, int pos = 0) const;`
// int rfind(const string &str, int pos = npos) const; // 查找str最后一次出现位置，从pos开始查找`
// int rfind(const char *s, int pos=npos) const;`
// int rfind(const char *s, int pos, int n) const; // 从pos查找s前n个字符出现的最后一次位置`
// int rfind(const char c, int pos=0) const;`
// string &replace(int pos, int n, const string &str); //替换从pos开始的n个字符为字符串str`
// string &replace(int pos, int n, const char *s);`
// find找不到时返回-1
#include <iostream>
#include <string>

using namespace std;

void testFind()
{
	string str1 = "abcdefghijklmnopqrstuvwxyz";
	int pos = str1.find("de", 0);
	cout << pos << endl;

	pos = str1.find(string("de"), 0);
	cout << pos << endl;

	pos = str1.rfind("de");
	cout << pos << endl;
}

void testReplace()
{
	string str1 = "abcdefghijklmnopqrstuvwxyz";
	str1.replace(5, 3, "LALALA");
	cout << str1 << endl;
}

int main()
{
	testFind();
	testReplace();
    return 0;
}
