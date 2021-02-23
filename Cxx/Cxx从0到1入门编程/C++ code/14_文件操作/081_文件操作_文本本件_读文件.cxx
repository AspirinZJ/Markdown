// 文本文件读文件
#include <iostream>
#include <string>
// 1. 包含头文件
#include <fstream>
using namespace std;

void test1()
{
    // 2. 创建流对象
    ifstream ifs;
    // 3. 打开文件并判断是否打开成功
    ifs.open("./test.txt", ios::in);
    if (!ifs.is_open()) {cout << "文件打开失败." << endl; return;}
    // 4. 读数据,有四种方式
    // 4.1 第一种
    // char buf[1024] = {0};
    // while (ifs >> buf) // 会一行一行地读，当读到文件末尾，会返回一个false
    // {
    //     cout << buf << endl;
    // }
    
    // 4.2 第二种
    // char buf[1024] = {0};
    // while (ifs.getline(buf, sizeof(buf))) // ifs.getline 第一个参数是起始位置，第二个参数是大小
    // {
    //     cout << buf << endl;
    // }
    
    // 4.3 第三种
    // string buf;
    // while (getline(ifs, buf))
    // {
    //     cout << buf << endl;
    // }

    // 4.4 第四种
    char c;
    while ((c = ifs.get()) != EOF) // get()函数每次只读一个字符，EOF: end of file，文件尾
    {
        cout << c;
    }
    // 5. 关闭文件
    ifs.close();
}

int main()
{
    test1();
    return 0;
}
