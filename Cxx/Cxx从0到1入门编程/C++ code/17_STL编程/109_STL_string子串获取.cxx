#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str = "Hello";
	string subs = str.substr(1, 2);
	cout << subs << endl;

	// 实用操作
	string email = "alice@sina.com";
	// 从邮件地址中获取用户名信息
	string username = email.substr(0, email.find('@', 0));
	cout << username << endl;

    return 0;
}
