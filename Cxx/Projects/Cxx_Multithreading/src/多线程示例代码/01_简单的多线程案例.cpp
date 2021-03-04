// Created by jackzhang on 2021/3/3.
#include <iostream>
#include <thread>

int number = 1;

int threadProc1()
{
	while (number < 100)
	{
		std::cout << "thread 1: " << number++ << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
	return 0;
}

int threadProc2()
{
	while (number < 100)
	{
		std::cout << "thread 2: " << number++ << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
	return 0;
}

int main()
{
	std::thread t1(threadProc1);
	std::thread t2(threadProc2);

	t1.join();
	t2.join();

	return 0;
}
