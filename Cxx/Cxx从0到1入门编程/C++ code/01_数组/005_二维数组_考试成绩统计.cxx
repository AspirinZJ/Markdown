#include <iostream>
#include <string>

using namespace std;


int main(int argc, char **argv)
{
  string nameArr[3] = {"Alice", "Bob", "Chase"};
  int scoreArr[3][3] = 
  {
    {100, 100, 100},
    {90, 80, 90},
    {100, 98, 89}
  };

  for (int i = 0; i < 3; i++)
  {
    int sum = 0;

    for (int j = 0; j < 3; j++)
    {
      sum += scoreArr[i][j];
    }
    cout << "The Score of " << nameArr[i] << "Student is:" << sum << endl;
  }

  return 0;
}
