// Created by jackzhang on 2021/3/2.
// C++11 之前用这个
#include <iostream>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 5

void *wait(void *);

int main()
{
	pthread_t threadArr[NUM_THREADS];

	pthread_attr_t attr; // 属性
	// init and set thread as joinable
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	for (int i = 0; i < NUM_THREADS; ++i)
	{
		std::cout << "main() is creating thread: " << i << std::endl;
		int ret = pthread_create(&threadArr[i], &attr, wait, (void *) &i);
		if (ret)
		{
			std::cerr << "Error: cannot create thread. Error code: " << ret << std::endl;
			exit(-1);
		}
	}

	void *status;
	// 删除属性，并等待其他线程
	pthread_attr_destroy(&attr);
	for (int i = 0; i < NUM_THREADS; ++i)
	{
		int ret = pthread_join(threadArr[i], &status);
		if (ret)
		{
			std::cerr << "Error: unable to join. Error code: " << ret << std::endl;
			exit(-1);
		}
		std::cout << "main: completed thread id: " << i << std::endl << "Exiting with status: " << status << std::endl;
	}

	std::cout << "main() exiting..." << std::endl;
	pthread_exit(nullptr);
}

void *wait(void *threadId)
{
	auto tid = (pthread_t) threadId;
	sleep(1);
	std::cout << "Sleeping in thread. " << "Thread with id: " << tid << " ...exiting.\n";
	pthread_exit(nullptr);
}