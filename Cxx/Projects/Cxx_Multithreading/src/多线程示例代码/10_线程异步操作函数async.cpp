// Created by jackzhang on 3/4/21.
#include <iostream>
#include <future>

using std::cout;

int func()
{
	cout << "calling func..." << std::endl;
	return 100;
}

int main()
{
	std::future<int> fut = std::async(std::launch::async, func);

	cout << "result: " << fut.get() << std::endl;

	return 0;
}

