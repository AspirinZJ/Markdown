//
// Created by jackzhang on 2021/1/5.
//

#ifndef PROJECT_BOSS_H
#define PROJECT_BOSS_H
#include <iostream>
#include "worker.h"

using namespace std;

class Boss : public Worker
{
public:
	Boss(int id, string name, int did);
	void ShowInfo() override;
	string GetDeptName() override;
};

#endif //PROJECT_BOSS_H
