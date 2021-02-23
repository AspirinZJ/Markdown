// 二进制文件写文件
#include <iostream>
// 1. 包含头文件
#include <fstream>
using namespace std;

class Person
{
    public:
        char mName[64];
        int mAge;
};

void test1()
{
    // 2. 创建流对象
    // ofstream ofs;
    // 不单独写open，利用构造函数指定文件路径和打开方式
    ofstream ofs("./Person.txt", ios::out | ios::binary);
    // 3. 打开文件
    // ofs.open("./Person.txt", ios::out | ios::binary);
    // 4. 写文件
    Person p = {"Alice" , 20};
    ofs.write((const char *)&p, sizeof(Person)); // write的第一个参数是const char格式的指针，第二个参数是大小
    // 5. 关闭文件
    ofs.close();
}

int main()
{
    test1();
    return 0;
}
