// Created by jackzhang on 2/23/21.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INPUT_SIZE 30

int main(int argc, char **argv)
{
	// 危险代码：scanf不会对转换错误报错，如果输入的含有字母，空格等，会转换错误
	/*	int num = 0;
		printf("Input a number: \n");
		scanf("%d", &num);
		printf("The number is: %d", num);*/

	// 推荐代码：
	char *ptr;
	long ret;
	char str[INPUT_SIZE];

	/*
	If successful, strtol() returns the converted long int value.
	If unsuccessful, strtol() returns 0 if no conversion could be performed. If the correct value is outside the range of representable values, strtol() returns LONG_MAX or LONG_MIN, according to the sign of the value. If the value of base is not supported, strtol() returns 0.
	If unsuccessful strtol() sets errno to one of the following values:
	Error Codes:
	EINVAL The value of base is not supported.
	ERANGE The conversion caused an overflow.
	 */
	printf("Input a number: \n");

	// read a line from the specified stream and store it into the string
	fgets(str, INPUT_SIZE, stdin);
	ret = strtol(str, &ptr, 10);    // 10: decimal
	if (LONG_MAX == ret || LONG_MIN == ret) { perror("!!Problem is->"); }
	else if (ret) { printf("The number is: %ld\n", ret); }
	else { printf("No number found input is->%s\n", ptr); }

	// try the following input:
	// 123 abc
	// 123abc
	// abc 123
	// abc123abc
	// 999999999999999999
	return 0;
}
