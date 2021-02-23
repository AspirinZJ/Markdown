// 抽象类不需要cxx来实现
#pragma once
#include <iostream>
#include <string>

using namespace std;

// 职工的抽象类
class Worker
{
public:
	virtual void ShowInfo() = 0; // 获取个人信息纯虚函数
	virtual string GetDeptName() = 0; // 获取岗位名称
	int m_id; // ID
	string m_name; // 姓名
	int m_deptId; // 所在部门ID
};