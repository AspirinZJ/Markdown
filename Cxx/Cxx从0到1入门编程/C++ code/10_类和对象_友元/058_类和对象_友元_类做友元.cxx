#include <iostream>

using namespace std;

class Building;

class GoodFriend
{
    public:
        GoodFriend();
        void visit();
        Building *building;
};

class Building
{
    // 类做友元，GoodFriend类可以访问本类中私有的成员
    friend class GoodFriend;
    public:
        Building();

    public:
        string m_livingRoom;

    private:
        string m_bedRoom;
};

// 类外写成员函数
Building::Building()
{
    cout << "Building constructor." << endl;
    this->m_livingRoom = "livingRoom";
    this->m_bedRoom = "bedRoom";
}

GoodFriend::GoodFriend()
{
    // 创建一个建筑物的对象
    cout << "new an object" << endl;
    this->building = new Building;
    cout << "Finished new." << endl;
}

void GoodFriend::visit()
{
    cout << "Calling visit function." << endl;
    cout << building->m_livingRoom << endl;
    cout << building->m_bedRoom << endl;
}

void test1()
{
    GoodFriend goodFriend;
    goodFriend.visit();
}

int main()
{
    test1();
    return 0;
}
