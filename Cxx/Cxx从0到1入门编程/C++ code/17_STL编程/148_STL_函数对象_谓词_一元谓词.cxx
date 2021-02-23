// 仿函数返回值为bool成为谓词
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class CGreaterThan5
{
public:
	// 一元谓词
	bool operator()(int val) {return (val > 5);}
};

int main()
{
	vector<int> vec;
	for (int i = 0; i < 10; i++) { vec.push_back(i); }

	// 查找容器中有没有大于5的数字
	//  find_if包含在标准头文件algorithm中，第一个参数和第二个参数是查找区间，为迭代器类型，第三个参数是一个仿函数
	// find_if返回找到的元素的迭代器
	vector<int>::iterator it = find_if(vec.begin(), vec.end(), CGreaterThan5()); // CGreaterThan5()创建了一个匿名对象

	if (it != vec.end()) {cout << "Found element greater than 5: " << *it << endl;}
	else {cout << "Didn't find element." << endl;}

	return 0;
}
