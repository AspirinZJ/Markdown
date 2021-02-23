//
// Created by jackzhang on 2021/1/5.
//

#ifndef PROJECT_EMPLOYEE_H
#define PROJECT_EMPLOYEE_H

#include <iostream>
#include "worker.h"

using namespace std;

class Employee : public Worker
{
public:
	Employee(int id, string name, int did);
	void ShowInfo() override;
	string GetDeptName() override;
};

#endif //PROJECT_EMPLOYEE_H
