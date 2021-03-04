// Created by jackzhang on 2021/3/3.
// 原子操作更接近内核，并通过这个新的头文件提供了多种原子操作数据类型，例如，atomic_bool,atomic_int等等
// 如果我们在多个线程中对这些类型的共享资源进行操作，编译器将保证这些操作都是原子性的
// 确保任意时刻只有一个线程对这个资源进行访问，编译器将保证，多个线程访问这个共享资源的正确性
// 从而避免了锁的使用，提高了效率。
// 用原子变量实现02_mutex互斥量.cpp的功能
#include <iostream>
#include <mutex>
#include <thread>
#include <atomic>

std::atomic<int> g_number(0);

int threadProc1();
int threadProc2();

int main()
{
	std::thread t1(threadProc1);
	std::thread t2(threadProc2);

	t1.join();
	t2.join();

	return 0;
}

int threadProc1()
{
	for (int i = 0; i < 100; ++i) { std::cout << "thread 1: " << ++g_number << std::endl; }

	return 0;
}

int threadProc2()
{
	for (int i = 0; i < 100; ++i) { std::cout << "thread 2: " << --g_number << std::endl; }

	return 0;
}
