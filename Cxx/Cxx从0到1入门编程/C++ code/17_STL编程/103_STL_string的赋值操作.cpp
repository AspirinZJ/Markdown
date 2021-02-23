#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str1;
	str1 = "Hello World"; // string & operator=(const char *s);
	cout << str1 << endl;

	string str2;
	str2 = str1; // string & operator=(const string &s);
	cout << str2 << endl;

	string str3;
	str3 = 'a'; // string & operator=(char c);
	cout << str3 << endl;

	string str4;
	str4.assign("Hello World.");// string & assign(const char *s);
	cout << str4 << endl;

	string str5;
	str5.assign("Hello World.", 5);// string & assign(const char *s, int n);
	cout << str5 << endl;

	string str6;
	str6.assign(str5);// string &assign(const string &s);
	cout << str6 << endl;

	string str7;
	str7.assign(5, 'a');// string &assign(int n, char c);
	cout << str7 << endl;

	return 0;
}