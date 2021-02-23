// 文本文件的写文件
#include <iostream>
// 1. 包含头文件
#include <fstream>
using namespace std;

void test1()
{
    // 2. 创建流对象
    ofstream ofs;
    // 3. 指定打开方式
    ofs.open("./test.txt", ios::out);
    // 4. 写数据
    ofs << "Test..." << endl;
    ofs << "Lala..." << endl;
    // 5. 关闭文件
    ofs.close();
}

int main()
{
    test1();
    return 0;
}
