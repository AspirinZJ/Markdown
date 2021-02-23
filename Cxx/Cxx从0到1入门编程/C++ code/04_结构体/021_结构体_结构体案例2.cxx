// 创建一个英雄结构体，成员姓名，年龄，性别
// 创建结构体数组存放5个英雄
// 通过冒泡排序，将英雄按年龄升序排序并打印输出
#include <iostream>
#include <string>

using namespace std;

struct Hero
{
    string heroName;
    int heroAge;
    char heroSex;
};

// 冒泡排序，按年龄升序排列
void bubbleSort(struct Hero heroArr[], int len);
void printHeroArrInfo(const Hero heroArr[], int len);

int main(int argc, char **argv)
{
    Hero heroArr[5] = 
    {
        {"Liubei", 23, 'M'},
        {"Guanyu", 22, 'M'},
        {"Zhangfei", 21, 'M'},
        {"Zhaoyun", 19, 'M'},
        {"Diaochan", 18, 'F'}
    };

    int heroArrLen = sizeof(heroArr) / sizeof(heroArr[0]);
    printHeroArrInfo(heroArr, heroArrLen);
    bubbleSort(heroArr, heroArrLen);
    printHeroArrInfo(heroArr, heroArrLen);

    return 0;
}


void bubbleSort(struct Hero heroArr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (heroArr[j].heroAge > heroArr[j + 1].heroAge)
            {
                struct Hero heroTmp = heroArr[j];
                heroArr[j] = heroArr[j+1];
                heroArr[j+1] = heroTmp;
            }
        }
    }
    return;
}

void printHeroArrInfo(const Hero heroArr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << "Hero name: " << heroArr[i].heroName << " Hero age: " << heroArr[i].heroAge << " Hero Sex: " << heroArr[i].heroSex << endl;
    }
    return;
}
