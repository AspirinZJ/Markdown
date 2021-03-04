// Created by jackzhang on 2021/3/3.
/*类 unique_lock 是通用互斥包装器，允许延迟锁定、锁定的有时限尝试、递归锁定、所有权转移和与条件变量一同使用。
unique_lock比lock_guard使用更加灵活，功能更加强大。
使用unique_lock需要付出更多的时间、性能成本。*/

#include <mutex>
#include <iostream>
#include <thread>
#include <vector>

std::mutex mu;
std::once_flag onceFlag;

void printFun(int, char);
void runOnce(int &);

int main()
{
	std::vector<std::thread> vThread;
	int num = 0;
	for (int i = 0; i < 10; ++i)
	{
		vThread.emplace_back(printFun, 50, '*');
		vThread.emplace_back(runOnce, std::ref(num));
	}

	for (auto &t : vThread) { t.join(); }
	std::cout << "num: " << num << std::endl;

	return 0;
}

void printFun(int num, char ch)
{
	// std::defer_lock表示先不设置锁状态，当运行lock()方法时再加锁
	std::unique_lock<std::mutex> locker(mu, std::defer_lock);

	if (locker.try_lock()) // 尝试加锁，如果成功则执行
	{ // 适合执行一个job的场景，一个线程执行就可以，可以用更新时间戳辅助
		for (int i = 0; i < num; ++i) { std::cout << ch; }
		std::cout << std::endl;
	}
}

void runOnce(int &num)
{
	// 只执行一次，适合延迟加载，多线程static变量情况
	std::call_once(onceFlag, [&num]() -> void { ++num; });
	// call_once保证函数fn只被执行一次
	// 如果有多个线程同时执行函数fn调用，则只有一个活动线程(active call)会执行函数
	// 其他的线程在这个线程执行返回之前会处于”passive execution”(被动执行状态)——不会直接返回
	// 直到活动线程对函数调用结束才返回。对于所有调用函数的并发线程，数据可见性都是同步的(一致的)。
}