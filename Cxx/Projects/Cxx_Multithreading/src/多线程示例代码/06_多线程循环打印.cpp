// Created by jackzhang on 2021/3/3.
// 某年滴滴打车公司题目：
// 有3个线程A，B， C， 请用多线程编程实现在屏幕上循环打印10次ABCABC...
// 其中A线程打印“A”， B线程打印“B”， C线程打印“C”
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <functional>
#include <condition_variable>

#define NUM_PRINT 10

std::mutex g_mu;
std::condition_variable g_cond;
int g_chDiff = 0;

void printChar(char);

int main()
{
	std::vector<std::thread> vThread;

	vThread.emplace_back(printChar, 'A');
	vThread.emplace_back(printChar, 'B');
	vThread.emplace_back(printChar, 'C');

	std::for_each(begin(vThread), end(vThread), std::mem_fn(&std::thread::join));
	// for (auto &th : vThread) { th.join();}

	return 0;
}

void printChar(char ch)
{
	const int chDiff = ch - 'A';
	for (int i = 0; i < NUM_PRINT; ++i)
	{
		std::unique_lock<std::mutex> locker(g_mu);
		g_cond.wait(locker, [&chDiff]() -> bool { return chDiff == g_chDiff; });
		std::cout << ch;
		g_chDiff = (chDiff + 1) % 3;
		locker.unlock();
		g_cond.notify_all();
	}
}