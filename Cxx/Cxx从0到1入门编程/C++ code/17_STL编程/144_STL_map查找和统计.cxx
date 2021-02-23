//find(key); // 查找key是否存在，若存在，返回该键值的元素的迭代器， 若不存在，返回map.end();`
//count(key); // 统计key元素的个数`
#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<int, int> mp;
	mp.insert(pair<int, int>(1, 10));
	mp.insert(make_pair(2, 20));
	mp.insert(map<int, int>::value_type(3, 30));
	mp.insert(map<int, int>::value_type(3, 30)); // map不能插入两个具有相同键值的元素
	// 查找
	map<int, int>::iterator pos = mp.find(3);
	if (mp.end() != pos) { cout << "Found element. Key: " << (*pos).first << ". Value: " << pos->second << endl; }
	else { cout << "No such element." << endl; }

	// 统计
	int num = mp.count(3);
	cout << "The number of element with key equals to 3 is : " << num << endl;

	return 0;
}
