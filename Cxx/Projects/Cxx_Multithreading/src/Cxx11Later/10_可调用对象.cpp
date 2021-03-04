// Created by jackzhang on 2021/3/3.
#include <iostream>
#include <mutex>
#include <future>

class A
{
public:
	void f(int x, char c) {}

	int operator()(int n) { return 0; }
};

void fun(int x) {}


int main()
{
	A a;
	std::thread t1(a, 0); // 传递的是a的拷贝给子线程
	std::thread t2(std::ref(a), 0); // 传递a的引用给子线程

	// 将a从主线程移动到子线程, 一旦移动不能再次使用a, std::move的前提是A有拷贝构造和移动构造，A里面没有所以std::move失效
	std::thread t3(std::move(a), 0);

	std::thread t4(A(), 0); // 传递临时对象给子线程

	std::thread t5(fun, 0); // 传递函数给子线程

	std::thread t6([](int val) -> int { return val * val; }, 0); // 传递lambda函数给子线程

	A a2;
	std::thread t7(&A::f, a2, 0, 'a'); // 传递a2的拷贝的成员函数给子线程

	std::thread t8(&A::f, &a2, 0, 'a'); // 传递a2的地址的成员函数给子线程



	// 对于async，上面的几种传递方式同样使用，这里不一一列举
	std::future<int> fu = std::async(std::launch::async, a, 0);

	return 0;
}