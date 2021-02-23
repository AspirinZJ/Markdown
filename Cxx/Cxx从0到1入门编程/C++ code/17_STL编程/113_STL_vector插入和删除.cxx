// push_back(ele); // 尾部插入`
// pop_back(); 删除最后一个元素`
// insert(const_iterator pos, ele); // 迭代器指向位置pos插入元素ele`
// insert(const_iterator pos, int count, ele); // 插入count个`
// erase(const_iterator pos); // 删除迭代器指向的元素`
// erase(const_iterator start, const_iterator end); // 删除迭代器从start到end之间的元素`
// clear(); // 删除容器中所有元素`
#include <iostream>
#include <vector>

using namespace std;

void printVec(vector<int> &vec)
{
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{cout << (*it) << ' ';}
	cout << endl;
}

int main()
{
	vector<int> vec1;
	for (int i = 0; i < 5; i++)
	{vec1.push_back(i);} // 利用尾插法插入数据
	printVec(vec1);

	// 删除最后一个数据
	vec1.pop_back();
	printVec(vec1);

	// 插入
	vec1.insert(vec1.begin() + 2, 100);
	printVec(vec1);

	vec1.insert(vec1.begin() + 4, 2, 10000);
	printVec(vec1);

	vec1.erase(vec1.begin() + 5);
	printVec(vec1);

	vec1.erase(vec1.begin()+1, vec1.end()-1);
	printVec(vec1);

	vec1.clear();
	printVec(vec1); // 清空

    return 0;
}