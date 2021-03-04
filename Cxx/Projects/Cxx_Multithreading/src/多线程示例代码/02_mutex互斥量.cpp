// Created by jackzhang on 2021/3/3.
#include <iostream>
#include <thread>
#include <mutex>

int number = 0;
std::mutex mu;

int threadProc1()
{
	for (int i = 0; i < 100; ++i)
	{
		mu.lock();
		std::cout << "thread 1: " << ++number << std::endl;
		mu.unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
	return 0;
}

int threadProc2()
{
	for (int i = 0; i < 100; ++i)
	{
		mu.lock();
		std::cout << "thread 2: " << ++number << std::endl;
		mu.unlock();
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
