// Created by jackzhang on 2021/3/3.
// 解决死锁方法1： 所有的锁顺序都相同
// 解决死锁方法2： 使用std::lock()
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
	void sharedPrint2(const std::string &, int);
protected:
private:
	std::mutex m_mu;
	std::mutex m_mu2;
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
		log.sharedPrint2("From main thread", i);
	}
	return 0;
}

void LofFile::sharedPrint(const std::string &str, int value)
{
	std::lock_guard<std::mutex> locker(this->m_mu);
	std::lock_guard<std::mutex> locker2(this->m_mu2);
	// this->ofs << str << ", " << value << std::endl;
	std::cout << str << ", " << value << std::endl;
}

void LofFile::sharedPrint2(const std::string &str, int value)
{
	// 解决死锁方法1： 所有的锁顺序都相同
	// 下面改成先锁锁1,再锁锁2
	std::lock_guard<std::mutex> locker2(this->m_mu2);
	std::lock_guard<std::mutex> locker(this->m_mu);


	// 或者直接使用std::lock()
	// std::lock(this->m_mu, this->m_mu2);
	// 第二个参数告诉locker mutex已经被锁住，locker只是获取mutex所有权，然后析构时解锁mutex
	// std::lock_guard<std::mutex> locker2(this->m_mu2, std::adopt_lock);
	// std::lock_guard<std::mutex> locker(this->m_mu, std::adopt_lock);


	// this->ofs << str << ", " << value << std::endl;
	std::cout << str << ", " << value << std::endl;
}

void fun1(LofFile &log)
{
	for (int i = 0; i < 1000; ++i)
	{
		log.sharedPrint("From subthread", i);
		usleep(1);
	}
}