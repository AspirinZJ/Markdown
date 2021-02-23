#include <stdio.h>

int fibonacci(int n)
{
	if (1 == n) { return 1; }
	else if (2 == n) { return 2; }
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
	int n;
	printf("Input n: \n");
	scanf("%d", &n);

	int result = fibonacci(n);
	printf("Result: %d\n", result);

	return 0;
}