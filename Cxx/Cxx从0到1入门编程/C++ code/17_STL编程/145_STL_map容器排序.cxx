// map默认按照键值升序排序
// 利用仿函数，可以改变map容器排序规则
#include <iostream>
#include <map>

using namespace std;

class CMyCompare
{
public:
	// 重载(), 降序排序
	bool operator()(const int &i1, const int &i2) const
	{ return i1 > i2; }
};

int main()
{
	map<int, int, CMyCompare> mp;
	mp.insert(pair<int, int>(3, 10));
	mp.insert(make_pair(2, 69));
	mp.insert(map<int, int>::value_type(5, 50));

	for (map<int, int, CMyCompare>::const_iterator cit = mp.begin(); cit != mp.end(); ++cit)
	{
		cout << "Key: " << cit->first << ". Value: " << cit->second << endl;
	}

	return 0;
}
