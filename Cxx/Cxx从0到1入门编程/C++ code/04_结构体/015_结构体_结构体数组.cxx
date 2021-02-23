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

  // 创建结构体数组
  Student stuArr1[3] = 
  {
    {"Alice", 18, 90},
    {"Bob", 19, 95},
    {"Charlie", 20, 90}
  };

  stuArr1[0].name = "Alen";

  // 遍历数组
  for (int i = 0; i < 3; i++)
  {
    cout 
      << "Name: " << stuArr1[i].name
      << " Age: " << stuArr1[i].age 
      << " Score: " << stuArr1[i].score 
      << endl;
  }


  return 0;
}
