// Created by jackzhang on 2/23/21.
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main(int argc, char **argv)
{
	char *ptr;
	long ret;
	char str[30];
	printf("Input the length of the dynamic array.\n");
	fgets(str, 30, stdin);
	ret = strtol(str, &ptr, 10);
	if (LONG_MIN == ret || LONG_MIN == ret) { perror("!!Problem->"); }
	else if (ret)
	{
		int *pArr = (int *) malloc(ret * sizeof(int));    // 类似于 int pArr[len];
		for (int i = 0; i < ret; ++i) { pArr[i] = i; }
		for (int i = 0; i < ret; ++i) { printf("%d ", pArr[i]); }
		free(pArr);
	}
	else { printf("Wrong input.\n"); }


	return 0;
}
