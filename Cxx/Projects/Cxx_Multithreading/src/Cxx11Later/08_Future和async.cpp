// Created by jackzhang on 2021/3/3.
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>

/*
std::mutex mu;
std::condition_variable cond;
*/

int factorial(int);

int main()
{
	// int ret; // ret子线程和父线程共享，需要加锁保护
	//	std::thread t1(factorial, 4, std::ref(ret));
	//	t1.join();

	// 下面的会立刻启动线程调用factorial函数
	// std::future<int> fu = std::async(factorial, 4); // 等同于std::future<int> fu = std::async(std::launch::aync | std::launch::deferred, factorial, 4);

	// 下面的不会创建子线程，会延期启动factorial函数直到get方法被调用，将在同一个线程中调用factorial函数
	// std::future<int> fu = std::async(std::launch::deferred, factorial, 4);

	// 下面的会再另一个线程中调用factorial
	std::future<int> fu = std::async(std::launch::async, factorial, 4);

	std::cout << "Test code." << std::endl;

	int ret = fu.get(); // future的get函数只能调用一次

	std::cout << "Result: " << ret << std::endl;

	return 0;
}

int factorial(int n)
{
	std::cout << "Start calculating..." << std::endl;

	int res = 1;
	for (int i = n; i > 1; --i) { res *= i; }

	return res;
}
