#include <iostream>

namespace mySpace
{
	int size;
	const float pi = 3.14;
	void print();
	// 命名空间的定义是可以嵌套的
	namespace innerSpace { int size; }// 两个size不会冲突，在两个空间里
}

void mySpace::print()
{ std::cout << "pi: " << pi << std::endl; } // pi不需要加作用域，因为print函数和pi在同一作用域

int main()
{
	mySpace::size = 10; // 命名空间的成员访问必须加作用域
	mySpace::innerSpace::size = 20;
	std::cout << mySpace::size << std::endl;
	std::cout << mySpace::innerSpace::size << std::endl;
	mySpace::print();

	return 0;
}