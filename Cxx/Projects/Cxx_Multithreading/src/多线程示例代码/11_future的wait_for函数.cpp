// Created by jackzhang on 3/4/21.
#include <iostream>
#include <future>


int main()
{
	std::future<int> future = std::async(std::launch::async, []() -> int
	{
		std::this_thread::sleep_for(std::chrono::seconds(3));
		return 10;
	});

	std::cout << "Waiting..." << std::endl;

	std::future_status status;

	do
	{
		status = future.wait_for(std::chrono::seconds(1));
		switch (status)
		{
			case std::future_status::ready:
				std::cout << "ready!\n";
				break;
			case std::future_status::timeout:
				std::cout << "timeout!\n";
				break;
			case std::future_status::deferred:
				std::cout << "deferred!\n";
				break;
		}
	} while (std::future_status::ready != status);


	return 0;
}

