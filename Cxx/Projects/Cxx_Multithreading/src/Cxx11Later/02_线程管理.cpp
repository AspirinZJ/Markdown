// Created by jackzhang on 2021/3/2.
#include <iostream>
#include <thread>
#include <unistd.h>

void fun1()
{
	std::cout << "fun1 is running." << std::endl;
}

class MyClass
{
public:
	void operator()()
	{
		for (int i = 0; i < 10; ++i)
		{
			std::cout << "from t1: " << i << std::endl;
			usleep(1);
		}
	}

	void operator()(const std::string &msg)
	{
		for (int i = 0; i < 10; ++i)
		{
			std::cout << "from t1: " << msg << std::endl;
			usleep(1);
		}
	}
};

int main()
{
	// std::thread t1(fun1); // t1开始运行

	// 线程也可以通过其他方式构造
	// MyClass myClass;
	// std::thread t1(myClass); // t1开始运行


	// std::thread t1((MyClass())); // t1开始运行

	std::string msg = "This is a message";
	// std::thread t1(MyClass(), std::ref(msg));
	std::thread t1(MyClass(), std::move(msg));

	// 线程对象只能被std::move 不能直接赋值
	std::thread t2 = std::move(t1);

	// std::this_thread::get_id()获取当前线程id号
	// 输出主线程id
	std::cout << "main thread id: " << std::this_thread::get_id() << std::endl;
	// 线程.get_id()获取线程id
	// t2 id
	std::cout << "t2 thread id: " << t2.get_id() << std::endl;


	for (int i = 0; i < 10; ++i)
	{
		std::cout << "from main: " << i << std::endl;
		usleep(1);
	}

	// t1.join();
	t2.join();

	// 最多可以使用的线程进行并发
	std::cout << "max thread number: " << std::thread::hardware_concurrency() << std::endl;

	return 0;
}
