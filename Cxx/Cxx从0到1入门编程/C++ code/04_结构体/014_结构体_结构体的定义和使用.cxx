#include <iostream>
#include <string>

using namespace std;

int main()
{
  // 创建学生数据类型，包括姓名，年龄，分数
  struct Student
  {
    string name;
    int age;
    int score;
  };

  // 通过学生类型创建具体的学生
  // 1.
  struct Student student1;
  Student student2; // 可以省略struct
  student1.name = "Jack";
  student1.age = 24;
  student1.score = 100;
  cout << "Name:\t" << student1.name << "Age:\t" << student1.age << "Score:\t" << student1.score << endl;

  // 2.
  struct Student student3 = {"Bruce", 25, 95};

  // 3.
  struct Book
  {
    string name;
    float price;
  }book1;

  book1.name = "Book";
  book1.price = 20.0;

  return 0;
}
