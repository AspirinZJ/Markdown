#include <iostream>
#include <string>

using namespace std;

struct Student
{
    string name;
    int age;
    float score;
};

// 值传递
void printStudent(struct Student s);
// 地址传递
void printStudent2(struct Student *pStudent);

int main(int argc, char **argv)
{
    Student student1 = {"Alice", 20, 90.5};

    // 通过print函数打印结构体信息
    printStudent(student1);
    cout << "Name: " << student1.name << " Age: " << student1.age << " Score: " << student1.score << endl;
    printStudent2(&student1);
    cout << "Name: " << student1.name << " Age: " << student1.age << " Score: " << student1.score << endl;

    return 0;
}

void printStudent(struct Student s)
{
    // 值传递不会改变实参的值
    s.age = 100;
    cout << "Name: " << s.name << " Age: " << s.age << " Score: " << s.score << endl;
    return;
}


void printStudent2(struct Student *pStudent)
{
    // 地址传递会改变实参的值
    pStudent->age = 100;
    cout << "Name: " << pStudent->name << " Age: " << pStudent->age << " Score: " << pStudent->score << endl;
    return;
}
