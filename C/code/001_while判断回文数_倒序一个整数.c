#include <stdio.h>

int main()
{
	int num = 0;
	printf("Please input the number: \n");
	scanf("%d", &num);

	int sum = 0;
	int numCopy = num;

	while (numCopy)
	{
		sum = sum * 10 + numCopy % 10;
		numCopy /= 10;
	}

	printf("%s\n", sum == num ? "是回文数" : "不是回文数");

	return 0;
}