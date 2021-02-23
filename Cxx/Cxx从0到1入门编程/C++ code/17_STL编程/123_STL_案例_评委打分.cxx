// 有五名选手ABCDE，10个评委分别给每一名选手打分，去掉最高分和最低分取平均分
// vector存放五名选手
// deque容器存放10名评委分数
// sort算法排序分数，去掉最高分和最低分
// 累加获得总分和平均分
#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
#include <vector>
#include <time.h>

using namespace std;

class CPerson // 选手类
{
public:
	CPerson(string name, int score)
	{
		this->m_name = name;
		this->m_score = score;
	}

	string m_name;
	float m_score;
};

void createPerson(vector <CPerson> &vec)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "Athlete_";
		name += nameSeed[i];
		CPerson person(name, 0);
		vec.push_back(person);
	}
}

void setScore(vector <CPerson> &vec)
{
	for (vector<CPerson>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		// 将评委分数放入deque容器
		deque<int> scoreDeq;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60; // 分数是60-100区间
			scoreDeq.push_back(score);
		}

		sort(scoreDeq.begin(), scoreDeq.end());    // 对分数排序
		scoreDeq.pop_front();    // 去除最低分
		scoreDeq.pop_back();    // 去除最高分

		int sum = 0;
		for (deque<int>::const_iterator dit = scoreDeq.begin(); dit != scoreDeq.end(); ++dit) { sum += (*dit); }
		float avg = (float) sum / scoreDeq.size();
		it->m_score = avg;
	}
}

int main()
{
	// 随机数种子
	srand((unsigned int) time(NULL));
	// 1. 创建五名选手的vector
	vector <CPerson> personVec;
	createPerson(personVec);
	// 2. 给五名选手打分
	setScore(personVec);
	// 3. 显示最后得分
	for (vector<CPerson>::const_iterator cit = personVec.begin(); cit != personVec.end(); ++cit)
	{
		cout << "The score of " << cit->m_name << " is: " << cit->m_score << endl;
	}
	return 0;
}
