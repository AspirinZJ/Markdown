//
// Created by jackzhang on 2021/1/5.
//
#include "employee.h"

#include <utility>

Employee::Employee(int id, string name, int did)
{
	this->m_id = id; this->m_name = std::move(name); this->m_deptId = did;
}

void Employee::ShowInfo()
{
	cout << "ID: " << this->m_id << ". Name: " << this->m_name << ". Dept: " << this->GetDeptName() << endl;
}
string Employee::GetDeptName()
{
	return string("Employee");
}
