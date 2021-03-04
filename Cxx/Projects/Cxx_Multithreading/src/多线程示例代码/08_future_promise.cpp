// Created by jackzhang on 2021/3/3.
// thread库提供了future用来访问异步操作的结果，因为一个异步操作的结果往往不能立即获取，只能在未来的某个时候从某个地方获取
// 这个异步操作的结果是一个未来的期待值，所以被称为future
// future和promise的作用是在不同线程之间传递数据。

//假设线程1需要线程2的数据，那么组合使用方式如下：
//1. 线程1初始化一个promise对象和一个future对象，promise传递给线程2，相当于线程2对线程1的一个承诺
//   future相当于一个接受一个承诺，用来获取未来线程2传递的值
//2. 线程2获取到promise后，需要对这个promise传递有关的数据，之后线程1的future就可以获取数据了。
//3. 如果线程1想要获取数据，而线程2未给出数据，则线程1阻塞，直到线程2的数据到达
#include <iostream>
#include <future>
#include <thread>

void display(std::future<int> &);

int main()
{
	std::promise<int> promise;
	std::future<int> value = promise.get_future(); // 将promise与future绑定

	std::thread t1(display, std::ref(value));
	std::this_thread::sleep_for(std::chrono::seconds (2));

	promise.set_value(10); // 给线程传值

	t1.join();

	return 0;
}

void display(std::future<int> &value)
{
	std::cout << "waiting..." << std::endl;
	auto result = value.get();
	std::cout << "Value: " << result << std::endl;
}