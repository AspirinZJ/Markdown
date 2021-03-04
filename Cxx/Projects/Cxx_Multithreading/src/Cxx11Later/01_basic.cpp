// Created by jackzhang on 2021/3/2.
#include <iostream>
#include <thread>
#include <unistd.h>

void fun1()
{
	std::cout << "fun1 is running." << std::endl;
}

int main()
{
	std::thread t1(fun1); // t1线程开始运行

	// t1.join(); // 主线程等待t1运行结束

	// 一旦detach就不能再join
	t1.detach(); // 主线程和t1线程独立，无需等待t1运行结束
	// 如果不sleep的话，可能主线程执行太快导致无法看到屏幕的打印输出
	sleep(1);

	// 判断线程是否joinable
	if (t1.joinable()) { t1.join(); }

	return 0;
}
