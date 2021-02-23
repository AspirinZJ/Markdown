#include <stdio.h>

// 定义回调函数
void printText()
{ printf("Hello World.\n"); }

// 定义实现回调函数的“调用函数”
void callPrintText(void (*callFunc)())
{ (*callFunc)(); }

// 定义带参形式的回调函数
int printTextParam(char *s)
{
	printf("%s", s);
	return 0;
}

// 定义实现带参回调函数的“调用函数”
void callPrintTextParam(int (*callBackFunc)(char *), char *s)
{
	int i = (*callBackFunc)(s);
	printf("return value: %d\n", i);
}

int main()
{
	callPrintText(printText);
	callPrintTextParam(printTextParam, "Hello World!\n");

	return 0;
}