#include <iostream>
#include <ctime>

using namespace std;

void randData(int *arr, int n)
{
	srand((unsigned int) time(NULL));
	for (int i = 0; i < n; ++i)
	{
		arr[i] = rand() % 100;
		cout << arr[i] << ' ';
	}
	cout << endl;
}

void swapInt(int *i1, int *i2)
{
	int tmp = *i1;
	*i1 = *i2;
	*i2 = tmp;
}

// 冒泡排序
void bubbleSort(int *arr, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1]) { swapInt(&arr[j], &arr[j + 1]); }
		}
	}
}

// 选择排序
void selectSort(int *arr, int len)
{
	for (int i = 0; i < len - 1; ++i)
	{
		int minInd = i;
		for (int j = i + 1; j < len; ++j) { if (arr[j] < arr[minInd]) minInd = j; }
		if (minInd != i) { swapInt(&arr[minInd], &arr[i]); }
	}
}

// 插入排序
void insertSort(int *arr, int len)
{
	for (int i = 1; i < len; ++i)
	{
		for (int j = i; j > 0; --j) { if (arr[j] < arr[j - 1]) { swapInt(&arr[j], &arr[j - 1]); }}
	}
}

// 快速排序
void quickSort(int *arr, int start, int end)
{
	// 需要用到递归, 下面为递归终止的条件
	if (start >= end) { return; }

	int head = start;
	int tail = end;
	int key = arr[start]; // 通常选择第一个元素为基准位

	while (head < tail)
	{
		while (head < tail && arr[tail] >= key) { tail--;} // 从后往前找，找到比基准位小的数移到左边
		arr[head] = arr[tail];

		while (head < tail && arr[head] <= key) { head++;} // 从前往后找，找到比基准位大的数放到右边
		arr[tail] = arr[head];
	}

	arr[head] = key; // 循环结束时，head==tail

	quickSort(arr, start, head-1); // 递归排序左边的
	quickSort(arr, head+1, end); // 递归排序右边的
}


void display(int *arr, int n)
{
	for (int i = 0; i < n; ++i) { cout << arr[i] << ' '; }
	cout << endl;
}

int main()
{
	const int N = 10;
	int arr[N];

	randData(arr, N);
	bubbleSort(arr, N);
	display(arr, N);

	cout << "------------------" << endl;
	randData(arr, N);
	bubbleSort(arr, N);
	display(arr, N);

	cout << "------------------" << endl;
	randData(arr, N);
	insertSort(arr, N);
	display(arr, N);

	cout << "------------------" << endl;
	randData(arr, N);
	quickSort(arr, 0, N-1);
	display(arr, N);

	return 0;
}