// 提供菜单界面交互
// 对演讲比赛进行流程控制
// 文件的读写交互
#ifndef PROJECT_SPEECHMANAGER_H
#define PROJECT_SPEECHMANAGER_H

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <random>
#include <deque>
#include <fstream>
#include <ctime>
#include "speaker.h"

class SpeechManager
{
public:
	SpeechManager();
	~SpeechManager();
	static void showMenu();    // 展示菜单
	void initSpeechManager(); // 初始化
	void createSpeaker(); // 创建选手
	void startSpeech(); // 开始比赛
	void shuffleId(); // 抽签
	void speechContest(); // 比赛
	void showScore(); // 显示分数
	void saveRecord(); // 保存记录
	void loadRecord(); // 读取记录
	void showRecord(); // 显示往届记录
	void clearRecord(); // 清空比赛记录

	int round; // 比赛轮数
	bool emptyFile; // 文件是否为空
	std::vector<int> v1; // 第一轮选手编号
	std::vector<int> v2; // 第一轮晋级的选手编号
	std::vector<int> vVictory; // 胜利选手编号
	std::map<int, Speaker> mapSpeaker; // 编号以及对应选手
	std::map<int, std::vector<std::string>>  mapRecord; // 记录往届信息的map容器
};

#endif //PROJECT_SPEECHMANAGER_H