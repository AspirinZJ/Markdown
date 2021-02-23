//
// Created by jackzhang on 2021/1/5.
//

#include"boss.h"

#include <utility>

Boss::Boss(int id, string name, int did)
{
	this->m_id = id; this->m_name = std::move(name); this->m_deptId = did;
}

void Boss::ShowInfo()
{
	cout << "ID: " << this->m_id << ". Name: " << this->m_name << ". Dept: " << this->GetDeptName() << endl;
}
string Boss::GetDeptName()
{
	return string("Boss");
}
