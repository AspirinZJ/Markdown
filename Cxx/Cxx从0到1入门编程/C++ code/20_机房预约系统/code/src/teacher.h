// Created by jackzhang on 2/18/21.

#ifndef INC_20__TEACHER_H
#define INC_20__TEACHER_H

#include <ostream>
#include <iostream>
#include <vector>

#include "identity.h"
#include "order.h"

class Teacher : public Identity
{
public:
	Teacher();
	Teacher(int empId, std::string name, std::string passwd);
	void operMenu() override;	// 菜单界面
	static void showAllOrder();	// 查看所有预约
	static void validOrder();	// 审核预约

	int m_empId;
};


#endif //INC_20__TEACHER_H
