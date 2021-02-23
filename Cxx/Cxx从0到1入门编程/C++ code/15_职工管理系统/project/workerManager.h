#pragma once // 防止头文件重复包含
#include <iostream>
#include <fstream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#define FILENAME "./empFile.txt"

using namespace std;

class WorkerManager
{
    public:
        WorkerManager();
        static void showMenu();
        void AddEmp(); // 添加职工
        void save() const; // 保存文件
        bool m_isEmpty;	// 数据文件是否为空
        static int getEmpNum(); // 统计文件中人数
        void initEmp() const; // 初始化员工
        void showEmp() const; // 显示职工信息
        int isExist(int id) const; // 按照编号判断是否存在，并返回在数组的位置
        int isExist(const string& name) const; // 按照姓名判断是否存在，并返回在数组的位置
        void delEmp(); // 按照职工编号进行删除
        void modEmp() const; // 修改职工信息
        void findEmp() const; // 查找职工
        void sortEmp() const; // 排序员工
        void cleanFile(); // 清空函数

        ~WorkerManager();

        int m_empNum; // number of workers
        Worker **pEmpArr; // pointer array of worker information
};
