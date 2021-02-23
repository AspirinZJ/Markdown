//构造函数：
//stack<T> stk; // 默认构造`
//stack(const stack<T> &stk); // 拷贝构造`
//
//赋值操作：
//stack &operator=(const stack &stk); // 重载=运算符`
//
//数据存取：
//push(elem); // 压栈，向栈顶添加元素`
//pop(); //弹栈，从栈顶移除`
//top(); // 返回栈顶元素`
//
//大小操作
//empty(); // 判断是否为空`
//size(); // 返回栈大小`
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> stk;
	stk.push(1);
	stk.push(5);
	stk.push(3);
	stk.push(2);

	//只要栈不为空，查看栈顶，并执行弹出操作
	while (!stk.empty())
	{
		// 查看栈顶元素
		cout << stk.top() << ' ';
		stk.pop();
	}
	cout << endl;
	cout << "The size of stack :" << stk.size() << endl;
	return 0;
}
