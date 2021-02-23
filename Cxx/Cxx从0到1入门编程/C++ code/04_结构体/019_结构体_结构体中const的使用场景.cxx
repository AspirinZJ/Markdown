#include <iostream>
#include <string>

using namespace std;

struct Student
{
    string name;
    int age;
    float score;
};

void printStudent(Student s);
void printStudent2(Student *s);  // 地址传递可以减少内存空间（不复制新的副本）
void printStudent3(const Student *s);  // 加了const之后只能读（解引用），但不能写（通过指针修改地址中存放的值）

int main(int argc, char **argv)
{
    Student student1 = {"Alice", 20, 90};
    // 通过函数打印结构体信息
    printStudent(student1);
    printStudent2(&student1);
    printStudent3(&student1);
    
    return 0;
}


void printStudent(Student s)
{
    s.age = 100;    // 值传递不会修改实参的值
    cout << "Name: " << s.name << " Age: " << s.age << " Score: " << s.score << endl;
    return;
}


void printStudent2(Student *s)
{
    s->age = 100;   // 地址传递会改变实参的值
    cout << "Name: " << s->name << " Age: " << s->age << " Score: " << s->score << endl;
    return;
}

void printStudent3(const Student *s)  // 加了const之后只能读（解引用），但不能写（通过指针修改地址中存放的值）
{
    // s->age = 100;   // 不能同过常量指针修改指向内容的值
    cout << "Name: " << s->name << " Age: " << s->age << " Score: " << s->score << endl;
    return;
}
