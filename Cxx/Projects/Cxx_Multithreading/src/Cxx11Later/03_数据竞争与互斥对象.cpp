// Created by jackzhang on 2021/3/3.
#include <iostream>
#include <thread>
#include <unistd.h>
#include <fstream>
#include <mutex>

// 创建一个互斥对象
std::mutex mu;


// 不是很好的做法，cout是全局对象，仍然可以被其他线程在不加锁的情况下使用
void sharedPrint(const std::string &, int);
void fun1();

// 较好的practice
class LofFile
{
public:
	LofFile();
	~LofFile();
	void sharedPrint(const std::string &, int); // 要使用此函数里面就一定会加锁
	// std::ofstream &getFileStream() { return this->f;} // 不好，这样就能在互斥对象的保护之外访问f，不加锁的情况下可以绕过访问
	// void processF(void (*fun)(std::ofstream &)) { (*fun)(f);} // 也不好，理由同上

protected:

private:
	std::mutex m_mutex;
	std::ofstream f; // f是被m_mutex保护的资源
};

void fun2(LofFile &);

int main()
{
	std::thread t1(fun1);

	for (int i = 0; i < 10; ++i)
	{
		// std::cout << "From main thread: " << i << std::endl; // 与子线程的cout竞争
		sharedPrint("From main thread: ", i);
		usleep(1);
	}

	t1.join();


	LofFile log;
	std::thread t2(fun2, std::ref(log));

	for (int i = 0; i < 10; ++i)
	{
		log.sharedPrint("From main thread: ", i);
		usleep(1);
	}

	t2.join();

	return 0;
}

void fun1()
{
	for (int i = 0; i < 10; ++i)
	{
		// std::cout << "From subthread: " << i << std::endl; // 与主线程的cout竞争,有时会输出到同一行
		sharedPrint("From subthread: ", i);
		usleep(1);
	}
}

void sharedPrint(const std::string &msg, int id)
{
	// 不推荐使用lock和unlock，否则lock之后抛出异常的话会被永远锁住
	// mu.lock();	// 加锁，一个线程打印时另一个线程会等待
	std::lock_guard<std::mutex> guard(mu); // 当guard被析构时，不管之间有没有异常，都会自动解锁
	std::cout << msg << id << std::endl; // 由于cout是全局对象，其他线程仍然可以在未加锁的情况下使用cout
	// mu.unlock();	// 解锁
}


void fun2(LofFile &log)
{
	for (int i = 0; i < 10; ++i)
	{
		log.sharedPrint("From subthread: ", i);
		usleep(1);
	}
}

LofFile::LofFile() { f.open("./log.txt"); }

void LofFile::sharedPrint(const std::string &msg, int value)
{
	std::lock_guard<std::mutex> locker(this->m_mutex);
	f << msg << ": " << value << std::endl;
}

LofFile::~LofFile() { f.close(); }
