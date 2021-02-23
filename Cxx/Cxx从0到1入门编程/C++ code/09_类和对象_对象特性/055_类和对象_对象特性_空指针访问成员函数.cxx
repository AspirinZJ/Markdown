#include <iostream>
using namespace std;

class Person
{
    public:
        void showClassName() {cout << "Person class. " << endl;}
        void showPersonAge() {cout << "Age: " << this->m_Age <<endl;}
        void showPersonAge2()
        {
            if (this == NULL) {return;} // 防止空指针，提高健壮性
            else {cout << "Age: " << this->m_Age << endl;}
        }
        int m_Age;
};

void test1()
{
    Person *p = NULL;
    p->showClassName();
    // p->showPersonAge();  // NULL指针无法调用showPersonAge, 因为无法调用this->m_Age; this指向NULL
    p->showPersonAge2();
}

int main()
{
    test1();
    return 0;
}
