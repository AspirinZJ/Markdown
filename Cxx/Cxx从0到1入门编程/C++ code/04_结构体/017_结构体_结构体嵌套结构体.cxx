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

  struct Teacher
  {
    int id;
    string name;
    int age;
    Student stu;
  };

  Teacher t1 = {1, "Teacher1", 50, {"Alice", 20, 90}};

  cout
      << "Teacher name: " << t1.name
      << " Teacher id: " << t1.id
      << " Teacher age: " << t1.age
      << " Student age: " << t1.stu.age
      << " Student name: " << t1.stu.name
      << " Student score: " << t1.stu.score
      << endl;

  return 0;
}
