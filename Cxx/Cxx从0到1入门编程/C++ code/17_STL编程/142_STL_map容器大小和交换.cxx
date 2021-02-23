//size(); `
//empty(); `
//swap(mp);// 交换两个集合容器`
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
	mp.insert(pair<int, int>(2, 20));
	mp.insert(pair<int, int>(1, 10));
	mp.insert(pair<int, int>(3, 30));
	printMap(mp);

	cout << "mp.empty(): " << mp.empty() << endl;
	cout << "mp.size(): " << mp.size() << endl;

	map<int, int> mp2 = {pair<int, int>(2, 5), pair<int, int>(1, 3)};
	mp2.swap(mp);
	printMap(mp);
	printMap(mp2);

	return 0;
}
