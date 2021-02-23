#include <iostream>
#include <string>
using namespace std;

class Building;

class GoodFriend
{
    public:
        GoodFriend();
        void visit(); // 让成员函数访问Building中的私有成员
        void visit2(); // 让visit2成员函数无法访问Building中的私有成员
        Building *building;
};

class Building
{
    // 告诉编译器GoodFriend类下的visit成员函数作为本类的友元，可以访问私有成员
    friend void GoodFriend::visit();
    public:
        Building();
    public:
        string m_livingRoom;
    private:
        string m_bedRoom;
};

// 类外实现成员函数
Building::Building() {this->m_livingRoom = "livingRoom", m_bedRoom = "bedRoom";}

GoodFriend::GoodFriend() {building = new Building;}

void GoodFriend::visit()
{
    cout << "visiting: " << building->m_livingRoom << endl;
    cout << "visiting: " << building->m_bedRoom << endl;
}

void GoodFriend::visit2()
{
    cout << "visiting2: " << building->m_livingRoom << endl;
    // cout << "visiting2: " << building->m_bedRoom << endl;
}

void test1()
{
    GoodFriend gf;
    gf.visit();
    gf.visit2();
}

int main()
{
    test1();
    return 0;
}
