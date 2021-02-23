//构造函数原型：
//map<T1, T2> mp; // 默认构造函数`
//map(const map &mp); // 拷贝构造函数`
//赋值函数原型：
//map &operator=(const map &mp); // 重载=运算符`

#include <iostream>
#include <map>

using namespace std;

void printMap(const map<int, int> &mp)
{
	for (map<int, int>::const_iterator cit = mp.begin(); cit != mp.end(); ++cit)
	{
		cout << "Key: " << (*cit).first << ". Value: " << (*cit).second << endl;
	}
}

int main()
{
	map<int, int> mp;

	// 插入会按照key值自动排序
	mp.insert(pair<int, int>(1, 10)); // 插入一个对组
	mp.insert(pair<int, int>(3, 30));
	mp.insert(pair<int, int>(2, 20));

	printMap(mp);


	// 拷贝构造
	map<int, int> mp2(mp);
	printMap(mp2);

	// 重载=
	map<int, int> mp3;
	mp3 = mp;
	printMap(mp3);

	return 0;
}
