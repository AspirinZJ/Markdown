#include <iostream>
#include <functional>

using namespace std;

int main()
{
	//negate一元仿函数，取反
	negate<int> neg;
	cout << "negate(50): " << neg(50) << endl;
	cout << "negate(50): " << negate<int>()(50) << endl; // 匿名对象

	// plus 二元仿函数，加法
	plus<int> pls;
	cout << "5 + 6 = " << pls(5, 6) << endl;
	cout << "5 + 6 = " << plus<int>()(5, 6) << endl; // 匿名对象

    return 0;
}
