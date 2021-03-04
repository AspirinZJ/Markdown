// C++11 之前这样写
#include <iostream>
#include <pthread.h>

#define NUM_THREADS 5

void *sayHello(void *);

int main()
{
	// 定义线程id的变量，多个变量使用数组
	pthread_t tid[NUM_THREADS];
	for (unsigned long &i : tid)
	{
		// 创建线程
		// 参数依次是: 创建的线程id， 线程参数，调用的函数，传入的参数函数
		int ret = pthread_create(&i, nullptr, sayHello, nullptr);
		// 0 表示创建线程成功，非0表示失败
		if (ret) { std::cout << "pthread_create error: error code: " << ret << std::endl; }
	}

	pthread_exit(nullptr);

	return 0;
}

// 线程运行的函数
void *sayHello(void *args)
{
	std::cout << "Hello World!\n";
	return nullptr;
}