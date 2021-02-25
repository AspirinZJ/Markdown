// Created by jackzhang on 2/23/21.
#include <stdio.h>
#include <stdlib.h>

void fun(int **q)
{
	int i = 5;
	*q = &i; // 函数执行完毕后，i会被释放
}

void fun2(int **q)
{
	*q = (int *) malloc(sizeof(int));
	**q = 5;
}

int main(int argc, char **argv)
{
	int *p;
	// fun(&p);
	fun2(&p);

	printf("*p: %d\n", *p);

	free(p);
	return 0;
}
