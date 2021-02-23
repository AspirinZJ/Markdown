#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int main()
{
	const int SIZE = 6;
	int array[SIZE] = {1, 2, 3, 4, 5, 6};

	// 初始化一个vector容器
	std::vector<int> intVec(array, array + SIZE);    // array是指向首元素的指针，array+size是指向最后一个元素下一个元素的指针
	std::cout << "First Element: " << intVec.front() << ". Last Element: " << intVec.back() << std::endl;

	intVec[1] = 20;    // 没有越界检测
	intVec.at(2) = 30;    // 有越界检测，会抛出异常

	intVec.insert(intVec.begin() + 2, 25); // 在第2个位置插入25
	intVec.push_back(70);

	std::vector<int>::iterator iter = intVec.begin();    // 声明一个迭代器, 迭代器是使用类似于指针，可以解引用
	while (iter != intVec.end()) { std::cout << *(iter++) << std::endl; }

	iter = find(intVec.begin(), intVec.end(), 25);    // 查找
	// 两个迭代器相减可以得到位置
	if (intVec.end() != iter) { std::cout << "Location: " << iter - intVec.begin() << std::endl; }
	else { std::cout << "No such element." << std::endl; }

	std::cout << "vector能分配的最大容量：" << intVec.max_size() << std::endl;
	std::cout << "当前最大容量： " << intVec.capacity() << std::endl;
	std::cout << "size: " << intVec.size() << std::endl;

	try {intVec.at(20) = 200;} // at会检查是否越界，是的话会抛出异常
	catch (std::out_of_range &error) { std::cout << "Exception: " << error.what();}

	intVec.erase(intVec.begin()); // erase the first element
	intVec.erase(intVec.begin(), intVec.end()); // erase the element within the range

	std::cout << "isEmpty: " << intVec.empty() << std::endl;

	intVec.insert(intVec.begin(), array, array+SIZE); // the first parameter is the insert position, [array, array+SIZE) is the range

	intVec.clear(); // clear all the data


	return 0;
}