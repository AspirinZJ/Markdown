// Created by jackzhang on 2021/3/3.
// std::packaged_task包装一个可调用的对象，并且允许异步获取该可调用对象产生的结果。
// std::packaged_task将其包装的可调用对象的执行结果传递给一个std::future对象，与std::promise某种程度上是很像的
// promise保存一个共享状态的值，而package_task保存的是一个函数。

#include <iostream>
#include <thread>
#include <future>

inline int func(int);

int main()
{
	std::packaged_task<int(int)> packagedTask(func);
	std::future<int> future = packagedTask.get_future();

	std::thread(std::move(packagedTask), 1).join();

	int ret  = future.get();
	std::cout << "Return: " << ret << std::endl;

	return 0;
}

inline int func(int value) { return ++value;}
