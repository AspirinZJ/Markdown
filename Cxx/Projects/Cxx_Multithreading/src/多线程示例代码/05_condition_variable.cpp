// Created by jackzhang on 2021/3/3.
#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>

std::mutex g_mu;
std::condition_variable g_cond;
bool g_ready = false;

void displayId(int);
void ready();

int main()
{
	std::thread tArr[8];
	for (int i = 0; i < 8; ++i) { tArr[i] = std::thread(displayId, i); }
	std::cout << "all thread lock...." << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(3));

	ready();

	for (auto &t : tArr) { t.join(); }

	return 0;
}

void displayId(int id)
{
	std::unique_lock<std::mutex> locker(g_mu);
	g_cond.wait(locker, []() -> bool { return g_ready; }); // 线程阻塞，直到第二个参数返回值为真
	std::cout << "id: " << id << std::endl;
}

void ready()
{
	std::unique_lock<std::mutex> locker(g_mu);
	g_ready = true;
	g_cond.notify_all(); // 唤醒所有的线程
}