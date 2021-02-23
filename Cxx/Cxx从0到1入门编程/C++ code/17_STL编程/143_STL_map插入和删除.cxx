//insert(elem); // 插入elem`
//clear(); // 清空容器`
//erase(pos); // 删除pos迭代器所指的元素，返回下一个元素的迭代器`
//erase(beg, end); // 删除区间[beg, end)的元素，返回下一个元素的迭代器`
//erase(key); // 删除容器中键值为key的元素`

#include <iostream>
#include <map>

using namespace std;

void printMap(const map<int, int> &mp)
{
	for (map<int, int>::const_iterator cit = mp.begin(); cit != mp.end(); ++cit)
	{
		cout << "Key: " << cit->first << ". Value: " << (*cit).second << endl;
	}
	cout << endl;
}

int main()
{
	map<int, int> mp;
	// insert()插入
	// 第一种
	mp.insert(pair<int, int>(1, 10));
	// 第二种
	mp.insert(make_pair(2, 20));
	// 第三种
	mp.insert(map<int, int>::value_type(3, 30));
	// 第四种, 不建议使用[]插入
	mp[4] = 40;
	printMap(mp);

	cout << mp[5] << endl; // 不存在键值为5的元素，会自动创建(5, 0)的元素
	printMap(mp);

	// 可以通过[key]访问
	cout << mp[4] << endl;

	// erase()删除
	mp.erase(mp.begin());
	printMap(mp);

	mp.erase(3); // 按照key删除
	printMap(mp);

	mp.erase(mp.begin(), mp.end());
	printMap(mp);

	mp.clear();

	return 0;
}
