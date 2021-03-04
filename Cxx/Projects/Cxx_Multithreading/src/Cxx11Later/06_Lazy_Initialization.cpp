// Created by jackzhang on 2021/3/3.
#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>

class LofFile
{
public:
	LofFile();
	~LofFile();
	void sharedPrint(const std::string &, int);
protected:
private:
	std::mutex m_mu;
	// std::mutex m_muOpen;
	std::once_flag m_onceFlag;
	std::fstream ofs;
};

void fun1(LofFile &);

int main()
{
	LofFile log;
	std::thread t1(fun1, std::ref(log));

	for (int i = 0; i < 1000; ++i) { log.sharedPrint("From main thread", i); }

	return 0;
}

void LofFile::sharedPrint(const std::string &str, int value)
{
	/*
		{
			std::unique_lock<std::mutex> locker(this->m_muOpen, std::defer_lock);
			if (!ofs.is_open())
			{
				this->ofs.open("./log3.txt");
			}
		}
	*/
	// 确保lambda函数只被调用一次，代码简洁正确
	std::call_once(this->m_onceFlag, [&]() { this->ofs.open("./log3.txt"); });

	std::unique_lock<std::mutex> locker(this->m_mu, std::defer_lock);
	this->ofs << str << ", " << value << std::endl; // 这部分会被unique_lock锁住
}


void fun1(LofFile &log)
{
	for (int i = 0; i < 1000; ++i) { log.sharedPrint("From subthread", i); }
}

LofFile::LofFile() = default;

LofFile::~LofFile() { this->ofs.close(); }