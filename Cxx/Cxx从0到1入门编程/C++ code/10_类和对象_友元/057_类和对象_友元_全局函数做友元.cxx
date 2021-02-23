#include <iostream>
using namespace std;

class Building
{
    // goodFriend是友元，可以访问类中的私有成员
    friend void goodFriend(Building *building);

    public:
        Building() {m_livingRoom = "livingRoom"; m_bedRoom = "bedRoom";}
        string m_livingRoom;

    private:
        string m_bedRoom;
};

//全局函数
void goodFriend(Building *building)
{
    cout << "全局函数访问: " << building->m_livingRoom << endl;
    cout << "全局函数访问: " << building->m_bedRoom << endl;
}

void test1()
{
    Building building;
    goodFriend(&building);
}

int main()
{
    test1();
    return 0;
}
