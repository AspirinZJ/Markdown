// 使用函数指针的步骤
// 1. 获取函数地址(函数名)
// 2. 声明函数指针
// 3. 使用函数指针来调用函数
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 实际中，为了使用方便，通常将函数指针用typedef来简化
typedef void (*FPTR)(char *);

void invoke(char *s);
void fun1(char *s);
void fun2(char *s);
void fun3(char *s);

int *fun4(int a, int b); // 指针函数，返回值为指针的函数

int main()
{
	// 函数指针
	void (*fPtr)(char *); // 将(*fPtr)看成一个函数
	fPtr = invoke;
	(*fPtr)("Hello World!\n");

	// 用typedef来实现
	FPTR fPtr2 = invoke;
	(*fPtr2)("Hello World!\n");

	// 函数指针数组
	FPTR fPtrArr[] = {fun1, fun2, fun3};
	(*fPtrArr[0])("Hello World!\n");

	// 指针函数，返回值为指针的函数
	int *p = NULL;
	p = fun4(21, 34);
	printf("%d\n", *p);

	return 0;
}

void invoke(char *s)
{ printf("%s", s); }

void fun1(char *s)
{ printf("%s", s); }

void fun2(char *s)
{ printf("%s", s); }

void fun3(char *s)
{ printf("%s", s); }

int *fun4(int a, int b)
{
	int *p = (int *)malloc(sizeof(int ));
	memset(p, 0, sizeof(int ));
	*p = a + b;
	return p;
}