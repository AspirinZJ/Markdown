#include <iostream>

namespace mySpace
{
	int size;
	const float pi = 3.14;
	void print();
	// 命名空间的定义是可以嵌套的
	namespace innerSpace { int size; }// 两个size不会冲突，在两个空间里
}

// 使用命名空间
using namespace mySpace;
void mySpace::print() // 函数实现时仍然需要加作用域，否则就会变成全局函数， 而不是mySpace作用域下的函数
{ std::cout << "pi: " << pi << std::endl; } // pi不需要加作用域，因为print函数和pi在同一作用域

int main()
{
	size = 10; // 命名空间的成员访问必须加作用域
	innerSpace::size = 20;
	std::cout << size << std::endl;
	std::cout << innerSpace::size << std::endl;
	print();

	return 0;
}