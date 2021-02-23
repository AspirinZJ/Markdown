//
// Created by jackzhang on 2021/1/5.
//
#include "manager.h"

#include <utility>

Manager::Manager(int id, string name, int did)
{
	this->m_id = id; this->m_name = std::move(name); this->m_deptId = did;
}
void Manager::ShowInfo()
{
	cout << "ID: " << this->m_id << ". Name: " << this->m_name << ". Dept: " << this->GetDeptName() << endl;
}
string Manager::GetDeptName() {return string("Manager");}
