// Created by jackzhang on 2021/3/3.
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

int factorial(int);

int main()
{
	std::thread t1(factorial, 4);
	std::this_thread::sleep_for(std::chrono::milliseconds(1)); // 延时1ms

	// 延时， 直到5ms后
	std::chrono::steady_clock::time_point timePoint = std::chrono::steady_clock::now() + std::chrono::milliseconds(5);
	std::this_thread::sleep_until(timePoint);

	t1.join();

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	std::mutex mu;
	std::unique_lock<std::mutex> locker(mu);
	locker.try_lock_for(std::chrono::milliseconds(1)); // locker锁住3ms

	locker.try_lock_until(timePoint);

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	std::condition_variable cond;
	cond.wait_for(locker, std::chrono::milliseconds(5));
	cond.wait_until(locker, timePoint);

	return 0;
}

int factorial(int n)
{
	int res = 1;
	for (int i = res; i > 1; --i) { res *= i; }

	return res;
}