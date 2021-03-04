// Created by jackzhang on 2021/3/2.
// C++11 之前这样写
#include <iostream>
#include <pthread.h>

#define NUM_THREADS 5

struct ThreadData
{
	int threadId;
	char *message;
};

void *printHello(void *);

int main()
{
	pthread_t tid[NUM_THREADS];
	struct ThreadData threadDataArr[NUM_THREADS];

	for (int i = 0; i < NUM_THREADS; ++i)
	{
		std::cout << "main() is creating thread: " << i << std::endl;
		threadDataArr[i].threadId = i;
		threadDataArr[i].message = (char *) "This is a message.";

		int ret = pthread_create(&tid[i], nullptr, printHello, (void *) (threadDataArr + i));
		if (ret)
		{
			std::cerr << "Error: failed to create thread. Error code: " << ret << std::endl;
			exit(-1);
		}
	}
	pthread_exit(nullptr);
}

void *printHello(void *args)
{
	struct ThreadData *pThreadData;
	pThreadData = (struct ThreadData *) args;
	std::cout << "Thread ID: " << pThreadData->threadId << "\nMessage: " << pThreadData->message << std::endl;

	pthread_exit(nullptr);
}