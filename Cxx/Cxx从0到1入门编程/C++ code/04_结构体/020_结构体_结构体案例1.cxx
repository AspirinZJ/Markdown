// 创建老师和学生的结构体，老师结构体中有姓名和学生结构体的数组
// 学生结构体有姓名和分数
// 执行打印操作
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct Student
{
    string name;
    int score;
};

struct Teacher
{
    string name;
    Student stuArr[5];
};

// 给老师赋值的函数
void allocateTeacher(Teacher arrTeacher[], int len);
void printTeacherInfo(Teacher arrTeacher[], int len);

int main(int argc, char **argv)
{
    // 随机数种子
    srand((unsigned int)time(NULL));
    // 创建函三个老师的数组
    Teacher arrTeacher[3];
    int len = sizeof(arrTeacher) / sizeof(arrTeacher[0]);
    // 通过函数给老师赋值同时给老师带的学生赋值
    allocateTeacher(arrTeacher, len);
    printTeacherInfo(arrTeacher, len);
    return 0;
}

void allocateTeacher(Teacher arrTeacher[], int len)
{
    char nameSeed = 'A';
    for (int i = 0; i < len; i++)
    {
        arrTeacher[i].name = "Teacher_";
        arrTeacher[i].name += nameSeed;
        nameSeed++;

        char nameSeedStudent = 'A';
        for (int j = 0; j < 5; j++)
        {
            arrTeacher[i].stuArr[j].name = "Student_";
            arrTeacher[i].stuArr[j].name +=  nameSeedStudent;
            nameSeedStudent++;
            int randNum = rand() % 61 + 40;
            arrTeacher[i].stuArr[j].score = randNum;
        }

    }
    return;
}


void printTeacherInfo(Teacher arrTeacher[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << "Teacher name: " << arrTeacher[i].name << endl;

        for (int j = 0; j < 5; j++)
        {
            cout << "Student name: " << arrTeacher[i].stuArr[j].name << endl;
            cout << "Student score: " << arrTeacher[i].stuArr[j].score << endl;
        }
    }
    return;
}
