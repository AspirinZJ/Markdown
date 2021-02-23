#include <iostream>
#include "speechManager.h"

int main()
{
	srand((unsigned int) time(nullptr));
	SpeechManager speechManager;
	/*
		for (std::map<int, Speaker>::iterator it = speechManager.mapSpeaker.begin();
			 it != speechManager.mapSpeaker.end(); ++it)
		{
			std::cout << "Id: " << it->first << ". Name: " << it->second.m_name << ". Score: " << it->second.m_Score[0]
					  << std::endl;
		}
		for (auto &it : speechManager.mapSpeaker)
		{
			std::cout << "Id: " << it.first << ". Name: " << it.second.m_name << ". Score: " << it.second.m_Score[0]
					  << std::endl;
		}
	*/

	int userChoice;
	while (true)
	{
		SpeechManager::showMenu();
		std::cout << "Please choose an option: " << std::endl;
		std::cin >> userChoice;
		switch (userChoice)
		{
			case 1: // 开始比赛
				speechManager.startSpeech();
				break;
			case 2: // 查看往届记录
				speechManager.showRecord();
				break;
			case 3: // 清空比赛记录
				speechManager.clearRecord();
				break;
			case 0: // 退出系统
				return 0;
			default:
				break;
		}
	}
}
