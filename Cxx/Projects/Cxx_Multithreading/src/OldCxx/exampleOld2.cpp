// Created by jackzhang on 2021/3/2.
// 以下简单的实例代码使用 pthread_create() 函数创建了 5 个线程，并接收传入的参数。
// 每个线程打印一个消息，并输出接收的参数，然后调用 pthread_exit() 终止线程
// C++11 之前这样写
#include <iostream>
#include <pthread.h>

#define NUM_THREADS 5

void *printHello(void *);

int main()
{
	pthread_t tid[NUM_THREADS];

	int ind[NUM_THREADS];
	for (int i = 0; i < NUM_THREADS; ++i) { ind[i] = i; }

	for (int i = 0; i < NUM_THREADS; ++i)
	{
		std::cout << "main() is creating threads: " << i << std::endl;
		int ret = pthread_create(&tid[i], nullptr, printHello, (void *) &ind[i]);

		if (ret)
		{
			std::cerr << "Error: cannot create thread. Error code: " << ret << std::endl;
			exit(-1);
		}
	}

	pthread_exit(nullptr);
}

void *printHello(void *threadid)
{
	// 对传入的参数进行强制类型转换，由void *转为 int *，然后再读取
	int tid = *((int *) threadid);
	std::cout << "Hello! Thread id: " << tid << std::endl;
	pthread_exit(nullptr);
}