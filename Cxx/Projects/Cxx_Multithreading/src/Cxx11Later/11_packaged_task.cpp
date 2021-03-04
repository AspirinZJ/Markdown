// Created by jackzhang on 2021/3/3.
#include <iostream>
#include <future>
#include <functional>
#include <deque>
#include <condition_variable>

std::deque<std::packaged_task<int()>> dqPackagedTask;
std::mutex mu;
std::condition_variable cond;

int factorial(int n)
{
	int res = 1;
	for (int i = n; i > 1; --i) { res *= i; }

	return res;
}

void thread1()
{
	std::packaged_task<int()> t;
	{
		std::unique_lock<std::mutex> locker(mu);
		cond.wait(locker, []() -> bool { return !dqPackagedTask.empty(); });
		t = std::move(dqPackagedTask.front());
	}
	t();
}

int main()
{
	std::thread t1(thread1);
	// package_task包括一个可调用对象，异步获取该可调用对象的结果
	// std::packaged_task<int()> packagedTask(std::bind(factorial, 4)); // 用lambda函数更好
	std::packaged_task<int()> packagedTask([]() -> int { return factorial(6); });
	std::future<int> ret = packagedTask.get_future();
	{
		std::unique_lock<std::mutex> locker(mu);
		dqPackagedTask.push_back(std::move(packagedTask));
	}
	cond.notify_one();
	int val = ret.get();
	std::cout << val << std::endl;
	t1.join();

	// 获得与package_task共享状态相关联的future对象, 异步访问
	// std::future<int> ret = packagedTask.get_future();

	// 等待任务完成并获取结果
	// int value = ret.get();
	// std::cout << "Value: " << value << std::endl;

	/*
		auto t = [] { return factorial(4); };
		std::cout << t() << std::endl;
	*/

	return 0;
}