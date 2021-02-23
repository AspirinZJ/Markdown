// Created by jackzhang on 2/23/21.
#include <stdio.h>

void swapWrong(int *, int *);
void swapRight(int *, int *);

int main(int argc, char **argv)
{
	int a = 1, b = 2;
	swapWrong(&a, &b);
	printf("a: %d, b: %d\n", a, b);

	swapRight(&a, &b);
	printf("a: %d, b: %d\n", a, b);

	return 0;
}

void swapWrong(int *p, int *q)
{
	// 只是更改了q和p存放的地址，并没有互换a和b
	int *t = p;
	p = q;
	q = t;
}

// 正确写法
void swapRight(int *p, int *q)
{
	int t = *p;
	*p = *q;
	*q = t;
}