// Created by jackzhang on 2021/3/3.
#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>

class LofFile
{
public:
	LofFile() = default;
	~LofFile() = default;
	void sharedPrint(const std::string &, int);
protected:
private:
	std::mutex m_mu;
};

void fun1(LofFile &);

int main()
{
	LofFile log;
	std::thread t1(fun1, std::ref(log));

	for (int i = 0; i < 1000; ++i)
	{
		// 如果子线程锁住了locker， 同时主线程锁住了locker2
		// 这样无论是sharedPrint还是sharedPrint2都被锁住了，造成了死锁
		log.sharedPrint("From main thread", i);
	}
	return 0;
}

void LofFile::sharedPrint(const std::string &str, int value)
{
	// std::lock_guard<std::mutex> locker(this->m_mu); // locker_guard不可以被std::move()

	// unique_lock比lock_guard更加消耗资源
	// 不加第二个参数的话立刻锁住之后的代码直到解锁，加第二个参数的化从lock开始锁
	std::unique_lock<std::mutex> locker(this->m_mu, std::defer_lock);
	std::cout << str << ", " << value << std::endl; // 这部分不会被锁住
	locker.lock(); // 加锁
	std::cout << str << ", " << value << std::endl; // 这部分会被unique_lock锁住
	locker.unlock();	// 解锁

	// 下面的代码不会被锁住
	// ...
	locker.lock(); // 再次加锁

	// unique_lock可以被std::move()
	std::unique_lock<std::mutex> locker2 = std::move(locker); // 控制权从locker转到locker2
}


void fun1(LofFile &log)
{
	for (int i = 0; i < 1000; ++i)
	{
		log.sharedPrint("From subthread", i);
		usleep(1);
	}
}
