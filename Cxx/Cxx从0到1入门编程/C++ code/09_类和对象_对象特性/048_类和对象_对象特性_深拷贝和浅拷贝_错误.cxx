#include <iostream>

using namespace std;

class Person
{
    public:
        int mAge;
        float *mHeight;
        Person() { cout << "默认构造函数" << endl;}
        Person(int age, float height) {
            cout << "有参构造函数" << endl;
            mAge = age;
            mHeight = new float(height);
        }

        // **** 自己实现拷贝构造函数，解决浅拷贝带来到问题
        ~Person() 
        {
            // 析构代码，将堆区开辟到数据释放
            if (mHeight != NULL)    {delete mHeight; mHeight = NULL;}
            cout << "析构函数" << endl;
        }
};

void test1()
{
    Person person1(18, 160.5);
    Person person2(person1);
    // 会报错，因为person1和person2的mHeight指针指向同一内存空间
    // 当调用完person2析构函数之后，person1中析构函数delete时会报错
}

// int main(int argc, char **argv)
int main()
{
    test1();
    return 0;
}
