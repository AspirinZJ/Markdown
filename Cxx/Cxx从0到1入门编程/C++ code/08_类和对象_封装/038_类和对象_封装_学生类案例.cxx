// 学生类案例，属性有姓名和学好，可以显示和给姓名学好赋值
#include <iostream>
#include <string>

using namespace std;

class Student
{
    public:
        string mName;
        int mId;

        // show Info
        void showName()
        {
            cout << "Name: " << mName << endl;
        }

        void showId()
        {
            cout << "Id: " << mId << endl;
        }

        // Change member value
        void setName(string name)
        {
            mName = name;
        }

        void setId(int id)
        {
            mId = id;
        }
};

int main(int argc, char **argv)
{
    Student student1;
    student1.mName = "Alice";
    student1.mId = 1;
    student1.showName();
    student1.showId();
    student1.setName("Bob");
    student1.setId(2);
    student1.showName();
    student1.showId();

    return 0;
}
