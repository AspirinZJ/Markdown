//replace_if(iterator beg, iterator end, _Pred, newvalue)`
//beg起始迭代器
//end结束迭代器
//_Pred谓词
//newvalue新值
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class CMyPrint
{
public:
	void operator()(const int &val)  const {cout << val << ' ';}
};

class CGreaterThan5
{
public:
	bool operator()(const int & val) const {return val > 5;}
};

int main()
{
	vector<int> iVec = {1, 2, 4, 2, 5, 12, 3, 123, 3};
	for_each(iVec.begin(), iVec.end(), CMyPrint()); cout << endl;
	replace_if(iVec.begin(), iVec.end(), CGreaterThan5(), 0);  //替换大于等于5的元素为0
	for_each(iVec.begin(), iVec.end(), CMyPrint()); cout << endl;

    return 0;
}
