// 实现一个通用的数组类，需要以下功能：
// 1. 可以对内置数据类型以及自定义数据类型进行存储
// 2. 将数组中的数据存放到堆区
// 3. 构造函数中可以传入数组的容量
// 4. 提供对应的拷贝构造函数以及operator=防止浅拷贝问题
// 5. 提供尾插法和尾删法对数组中的元素增加和删除
// 6. 可以通过下标的方式访问数组中的元素
// 7. 可以获取数组中当前元素个数和数组的容量
#ifndef C_CODE_MYARRAY_HPP
#define C_CODE_MYARRAY_HPP

#include <iostream>

using namespace std;

template<class T>
class CMyArray
{
public:
	explicit CMyArray(int capacity)
	{
		this->m_capacity = capacity;
		this->m_size = 0;
		pArr = new T[this->m_capacity];
	}

	// 拷贝构造，防止浅拷贝
	CMyArray(const CMyArray<T> &arr)
	{
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		this->pArr = new T[this->m_capacity]; // 深拷贝
		// 将arr中的数据都拷贝
		for (int i = 0; i < this->m_size; i++) { pArr[i] = arr.pArr[i]; }
	}

	// 重载=防止浅拷贝
	CMyArray &operator=(const CMyArray<T> &arr)
	{
		if (&arr != this) // 防止自己对自己用=操作
		{
			// 先判断原来堆区是否有数据，如果有先释放
			if (nullptr != this->pArr)
			{
				delete[] this->pArr;
				this->pArr = nullptr;
				this->m_capacity = 0;
				this->m_size = 0;
			}

			// 深拷贝
			this->m_capacity = arr.m_capacity;
			this->m_size = arr.m_size;
			pArr = new T[this->m_capacity];
			for (int i = 0; i < this->m_size; i++) { this->pArr[i] = arr.pArr[i]; }
		}

		return *this;
	}

	// 尾插法插入数据
	void pushBack(const T &element)
	{
		// 判断是否超出容量
		if (this->m_size >= this->m_capacity)
		{
			cout << "Capacity full." << endl;
			return;
		}
		this->pArr[this->m_size] = element; // 在末尾插入数据
		this->m_size++;
	}

	// 尾删法删除数据
	void popBack()
	{
		// 让用户访问不到最后一个元素，即为尾删
		this->m_size = (this->m_size <= 0) ? 0 : (this->m_size - 1);
	}

	// 重载[]
	T &operator[](int index)
	{ return this->pArr[index]; }

	int getCapacity()
	{ return this->m_capacity; }

	int getSize()
	{ return this->m_size; }

	~CMyArray()
	{
		if (nullptr != this->pArr)
		{
			delete[] this->pArr;
			this->pArr = nullptr;
		}
	}

private:
	T *pArr; // 指向堆区开辟的真实的数组
	int m_capacity{}; // 数组容量
	int m_size{}; // 数组大小
};

#endif //C_CODE_MYARRAY_HPP
