#include <iostream>
#include <string>

using namespace std;

int main()
{
  struct Student
  {
    string name;
    int age;
    float score;
  };

  // 创建结构体变量
  Student student1 = {"Alice", 20, 90};

  // 通过指针指向结构体变量
  Student *pStudent = &student1;

  // 通过指针访问结构体变量中的内容
  cout
    << "Name: " << pStudent->name
    << " Age: " << pStudent->age
    << " Score: " << pStudent->score
    << endl;


  return 0;
}
