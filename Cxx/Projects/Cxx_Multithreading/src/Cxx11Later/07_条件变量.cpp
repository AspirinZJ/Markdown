// Created by jackzhang on 2021/3/3.
#include <deque>
#include <iostream>
#include <functional>
#include <mutex>
#include <thread>
#include <condition_variable> // 条件变量

std::deque<int> q; // 将q加锁保护，防止fun1和fun2数据竞争
std::mutex mu; // 互斥对象
std::condition_variable cond; // 条件变量

void fun1();
void fun2();

int main()
{
	std::thread t1(fun1);
	std::thread t2(fun2);
	t1.join();
	t2.join();

	return 0;
}

void fun1()
{
	int count = 10;
	while (count > 0)
	{
		std::unique_lock<std::mutex> locker(mu);
		q.push_front(count);
		locker.unlock();
		cond.notify_one(); // 激活一个等待这个条件的线程
		// cond.notify_all(); // 激活所有的线程
		std::this_thread::sleep_for(std::chrono::seconds(1));
		--count;
	}
}

void fun2()
{
	int data = 0;
	while (1 != data)
	{
		std::unique_lock<std::mutex> locker(mu);
		/*
		if (!q.empty())
		{
			data = q.back();
			q.pop_back();
			locker.unlock();
			std::cout << "t2 got a value from t1: " << data << std::endl;
		} else
		{
			locker.unlock();
			// 不sleep一直循环非常消耗资源
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
		*/
		// 先解锁locker，休眠直到cond调用notify_one才激活， 再加锁，所以只能使用unique_lock
		// 第二个参数是lambda函数，防止t2自激活
		cond.wait(locker, []() -> bool { return !q.empty(); });
		data = q.back();
		q.pop_back();
		locker.unlock();
		std::cout << "t2 got a value from t1: " << data << std::endl;
	}
}