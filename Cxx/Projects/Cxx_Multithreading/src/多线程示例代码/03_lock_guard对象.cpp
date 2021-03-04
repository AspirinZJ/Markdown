// Created by jackzhang on 2021/3/3.
/*每次都要对mutex变量进行锁以及解锁，有时候忘记解锁就凉凉了。
所以c++11还提供了一个lock_guard类，它利用了RAII机制可以保证安全释放mutex。
在std::lock_guard对象构造时，传入的mutex对象(即它所管理的mutex对象)会被当前线程锁住。
在lock_guard对象被析构时，它所管理的mutex对象会自动解锁，不需要程序员手动调用lock和unlock对mutex进行上锁和解锁操作。
lock_guard对象并不负责管理mutex对象的生命周期，lock_guard对象只是简化了mutex对象的上锁和解锁操作
方便线程对互斥量上锁，即在某个lock_guard对象的生命周期内，它所管理的锁对象会一直保持上锁状态；
而lock_guard的生命周期结束之后，它所管理的锁对象会被解锁。
程序员可以非常方便地使用lock_guard，而不用担心异常安全问题。*/
#include <iostream>
#include <thread>
#include <mutex>

int gNumber = 0;
std::mutex mu;

int threadProc1()
{
	std::lock_guard<std::mutex> locker(mu);
	for (int i = 0; i < 100; ++i)
	{
		std::cout << "thread 1: " << ++gNumber << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	return 0;
}

int threadProc2()
{
	std::lock_guard<std::mutex> locker(mu);
	for (int i = 0; i < 100; ++i)
	{
		std::cout << "thread 2: " << --gNumber << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
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