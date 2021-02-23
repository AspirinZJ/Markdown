#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	string str1 = "hello";
	string str2 = "hello";
	string str3 = "world";

	cout << (str1.compare(str2)) << endl;
	cout << (str1.compare(str3)) << endl;
	cout << (strcmp("hello", "hello"))<< endl;

    return 0;
}
