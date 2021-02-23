#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector <vector<int>> intVecVec; // 容器嵌套容器
	// 创建一些小容器
	vector<int> intVec1;
	vector<int> intVec2;
	vector<int> intVec3;

	// 向小容器中添加数据
	for (int i = 0; i < 5; i++)
	{
		intVec1.push_back(i);
		intVec2.push_back(i + 1);
		intVec3.push_back(i + 2);
	}

	// 将小容器插入到大容器中
	intVecVec.push_back(intVec1);
	intVecVec.push_back(intVec2);
	intVecVec.push_back(intVec3);

	// 通过大容器，把所有数据遍历一遍
	for (vector < vector < int >> ::iterator itVecVec = intVecVec.begin(); itVecVec != intVecVec.end();
	itVecVec++)
	{
		for (vector<int>::iterator itVec = (*itVecVec).begin(); itVec != (*itVecVec).end(); itVec++)
		{
			cout << (*itVec) << endl;
		}
	}

	return 0;
}
