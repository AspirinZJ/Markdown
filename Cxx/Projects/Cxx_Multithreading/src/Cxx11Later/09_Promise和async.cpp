// Created by jackzhang on 2021/3/3.
#include <future>
#include <iostream>
#include <thread>

long factorial(std::future<int> &f)
{
	int res = 1;
	for (int i = f.get(); i > 1; --i) { res *= i; }

	return res;
}

int main()
{
	std::promise<int> p;
	std::future<int> f = p.get_future();
	std::future<long> fu = std::async(std::launch::async, factorial, std::ref(f));

	// std::shared_future<int> sharedFuture = f.share();
	// std::future<long> fu = std::async(std::launch::async, factorial, sharedFuture);
	// std::future<long> fu2 = std::async(std::launch::async, factorial, sharedFuture);

	p.set_value(4);

	int ret = fu.get();
	std::cout << "Result: " << ret << std::endl;

	return 0;
}