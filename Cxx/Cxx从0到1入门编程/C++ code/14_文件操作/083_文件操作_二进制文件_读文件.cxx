#include <iostream>
// 1. 包含头文件
#include <fstream>
using namespace std;

class Person
{
    public:
        char _Name[64];
        int _Age;
};

void test1()
{
    // 2. 创建流对象
    ifstream ifs;
    // 3. 打开文件
    ifs.open("./Person.txt", ios::binary | ios::in);
    // 4. 判断是否打开成功
    if (!ifs.is_open()) {cout << "Fail to open the file." << endl; return;}
    // 5. 读文件
    Person person;
    ifs.read((char *)&person, sizeof(person));
    cout << person._Name << endl << person._Age <<endl;
    // 6. 关闭文件
    ifs.close();
}

int main()
{
    test1();
    return 0;
}
