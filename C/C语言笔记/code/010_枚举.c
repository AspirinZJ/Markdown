// Created by jackzhang on 2021/2/23.
#include <stdio.h>


enum Week
{
	Monday = 2, Tuesday = 5, Wednesday = 6, Thursday = 0, Friday = 4, Saturday = 1, Sunday = 3
};

int main()
{
	enum Week week = Wednesday;

	printf("%d \n", week);

	switch (week)
	{
		case 2:
			printf("Monday.\n");
			break;
		case 5:
			printf("Tuesday.\n");
			break;
		case 6:
			printf("Wednesday.\n");
			break;
		case 0:
			printf("Thursday.\n");
			break;
		case 4:
			printf("Friday.\n");
			break;
		case 1:
			printf("Saturday.\n");
			break;
		case 3:
			printf("Sunday.\n");
			break;
		default:
			break;
	}

	return 0;
}