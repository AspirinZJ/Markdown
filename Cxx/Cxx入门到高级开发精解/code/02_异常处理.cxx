#include <iostream>

using namespace std;

void func()
{
	int a = 5, b = 0;
	if (0 == b) throw "Error: Divided by 0!"; // 显式地抛出一个异常
	else if (1 == b) throw 404;
	// 抛出异常后异常后面的代码不会被执行
	int c = a / b;
}

int main()
{
	try { func(); } // 将可能出现异常的块用try包裹
	catch (const char *error) { cout << error << endl; } // catch 参数要和抛出的异常类型匹配
	catch (int errorCode) { cout << errorCode << endl;}
	catch (...) {cout << "Caught error!" << endl;} // 所有异常都可以被捕获，针对性差，通用性强，一般放在后面
	return 0;
}