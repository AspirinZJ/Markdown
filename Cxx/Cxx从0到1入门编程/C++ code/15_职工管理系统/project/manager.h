//
// Created by jackzhang on 2021/1/5.
//

#ifndef PROJECT_MANAGER_H
#define PROJECT_MANAGER_H

#include <iostream>
#include "worker.h"

using namespace std;

class Manager : public Worker
{
public:
	Manager(int id, string name, int did);
	void ShowInfo() override;
	string GetDeptName() override;
};

#endif //PROJECT_MANAGER_H
