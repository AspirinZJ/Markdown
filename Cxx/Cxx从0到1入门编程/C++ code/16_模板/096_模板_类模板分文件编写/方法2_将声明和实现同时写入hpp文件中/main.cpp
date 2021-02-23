#include <iostream>
#include "person.hpp"

void test1()
{
	Person<string, int> person("Alice", 19);
	person.showPerson();
}

int main()
{
	test1();
	return 0;
}
