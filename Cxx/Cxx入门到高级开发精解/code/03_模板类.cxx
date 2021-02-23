#include <iostream>

template<class T = int> // 模板参数可以有默认值
class CStack // 栈类
{
public:
	CStack(int size = 10); // 默认构造函数
	~CStack();
	bool push(const T &); // 压栈
	T &pop();// 弹栈
	bool isEmpty() const;
	bool isFull() const;
	void printOn(std::ostream &);

private:
	int m_size;
	int m_top;
	T *m_stackPtr;
};

// 模板类的每一个函数都是模板函数，在类外实现时需要加上模板声明
template<class T>
CStack<T>::CStack(int size)
{
	this->m_size = size;
	this->m_top = -1;
	m_stackPtr = new T[size];
}

template<class T>
CStack<T>::~CStack()
{
	delete[] m_stackPtr;
	m_stackPtr = nullptr;
}

template<class T>
bool CStack<T>::push(const T &elem)
{
	if (!this->isFull())
	{
		this->m_stackPtr[++this->m_top] = elem;
		return true;
	}
	else { return false; }
}

template<class T>
T &CStack<T>::pop()
{
	if (!this->isEmpty()) { return this->m_stackPtr[this->m_top--]; }
	else { throw "Error: Stack Empty!"; }
}

template<class T>
bool CStack<T>::isEmpty() const
{ return this->m_top == -1; }

template<class T>
bool CStack<T>::isFull() const
{ return this->m_size - 1 == this->m_top; }

template<class T>
void CStack<T>::printOn(std::ostream &os)
{
	for (int i = 0; i <= this->m_top; i++) { os << this->m_stackPtr[i] << ' '; }
	os << std::endl;
}

int main()
{
	CStack<int> stack1;
	stack1.push(1);
	stack1.push(2);
	std::cout << "isEmpty: " << stack1.isEmpty() << std::endl;
	std::cout << "isFull: " << stack1.isFull() << std::endl;
	stack1.printOn(std::cout);

	stack1.pop();
	stack1.pop();
	std::cout << "isEmpty: " << stack1.isEmpty() << std::endl;
	std::cout << "isFull: " << stack1.isFull() << std::endl;

	return 0;
}