#include "speechManager.h"

SpeechManager::SpeechManager()
{
	this->initSpeechManager();
	this->createSpeaker();
	this->loadRecord();
}

SpeechManager::~SpeechManager()
= default;

void SpeechManager::showMenu()
{
	std::cout << "*********************************" << std::endl
			  << "**********欢迎参加演讲比赛**********" << std::endl
			  << "*********1. 开始演讲比赛***********" << std::endl
			  << "*********2. 查看往届记录***********" << std::endl
			  << "*********3. 清空比赛记录***********" << std::endl
			  << "*********0. 退出比赛程序***********" << std::endl
			  << "*********************************" << std::endl << std::endl;
}

void SpeechManager::initSpeechManager()
{
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->mapSpeaker.clear();
	this->mapRecord.clear();
	this->round = 1;
}

void SpeechManager::createSpeaker()
{
	std::string nameSeed = "abcdefghijkl";
	for (int i = 0; i < nameSeed.size(); ++i)
	{
		std::string name = "User_";
		name += nameSeed[i];

		Speaker speaker;
		speaker.m_name = name;

		for (double &j : speaker.m_Score) { j = 0.0; }

		this->v1.push_back(i + 10001);// 创建选手编号，并放入到v1容器中
		this->mapSpeaker.insert(std::make_pair(i + 10001, speaker)); // map选手编号以及对应的选手
	}
}

void SpeechManager::startSpeech()
{
	// 第一轮比赛
	this->shuffleId();// 1. 抽签
	// 2. 比赛
	this->speechContest();
	// 3. 显示晋级结果
	this->showScore();

	// 第二轮比赛
	++(this->round);
	// 1. 抽签
	this->shuffleId();
	// 2. 比赛
	this->speechContest();
	// 3. 显示最终结果
	this->showScore();
	// 4. 保存分数到文件
	this->saveRecord();
	// 5. 重置比赛状态并获取记录
	this->initSpeechManager();
	this->createSpeaker();
	this->loadRecord();

	std::cout << "This contest has been finished.\n";
}

void SpeechManager::shuffleId()
{
	std::cout << "第" << this->round << "轮的比赛选手进行抽签。\n" << "---------------------------\n"
			  << "抽签后演讲顺序如下：\n";

	if (1 == round) // 第一轮比赛
	{
		std::shuffle(this->v1.begin(), this->v1.end(), std::mt19937(std::random_device()()));

		/*
				for (std::vector<int>::const_iterator cit = v1.begin(); cit != v1.end(); ++cit)
				{
					std::cout << *cit << " ";
				}
		*/
		for (int it : v1) { std::cout << it << " "; }
		std::cout << std::endl;
	}
	else if (2 == round)
	{
		std::shuffle(this->v2.begin(), this->v2.end(), std::mt19937(std::random_device()()));
		for (int it : v2) { std::cout << it << " "; }
		std::cout << std::endl;
	}
}

void SpeechManager::speechContest()
{
	std::cout << "This is the " << this->round << "th round contest.\n";

	std::multimap<double, int, std::greater<>> group;// 存放小组成绩的临时容器
	int num = 0;

	std::vector<int> v_Src;
	if (this->round == 1) { v_Src = this->v1; }
	else { v_Src = this->v2; }

	// 遍历所有选手进行比赛
	for (std::vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); ++it)
	{
		++num;
		// 评委打分
		std::deque<double> scoreDeq;
		for (int i = 0; i < 10; ++i)
		{
			scoreDeq.push_back(0.1 * (random() % 401 + 600)); // 第i个评委的分数
		}

		std::sort(scoreDeq.begin(), scoreDeq.end(), std::greater<>()); // 降序排列
		scoreDeq.pop_front(); // 去掉一个最高分
		scoreDeq.pop_back(); // 去掉一个最低分

		double sum = std::accumulate(scoreDeq.begin(), scoreDeq.end(), 0.0); // 第三个参数是起始累加值
		double avg = sum / scoreDeq.size(); // 平均分

		this->mapSpeaker[*it].m_Score[this->round - 1] = avg; // 将分数放入到map容器

		// 将打分的数据放入到临时的小组容器中
		group.insert(std::make_pair(avg, *it));
		// 每6人取出前三名晋级
		if (0 == num % 6)
		{
			std::cout << "第" << num / 6 << "小组名次: " << std::endl;
			for (std::multimap<double, int>::const_iterator cit = group.begin(); cit != group.end(); ++cit)
			{
				std::cout << "Id: " << cit->second << ". Name: " << this->mapSpeaker[cit->second].m_name
						  << ". Score: " << this->mapSpeaker[cit->second].m_Score[this->round - 1] << std::endl;
			}
			std::cout << std::endl;

			// 取走前三名
			int count = 0;
			for (std::multimap<double, int>::iterator itWinner = group.begin();
				 itWinner != group.end() && count != 3; ++itWinner, ++count)
			{
				if (this->round == 1) { this->v2.push_back((*itWinner).second); }
				else if (this->round == 2) { this->vVictory.push_back((*itWinner).second); }
			}
			group.clear(); // 清空小组的内容
		}
	}
	std::cout << "第" << this->round << "轮比赛完毕.\n" << "------------------------------\n";
}

void SpeechManager::showScore()
{
	std::cout << "第" << this->round << "轮晋级选手如下：\n";

	std::vector<int> *pVec;
	if (1 == this->round) { pVec = &(this->v2); }
	else { pVec = &(this->vVictory); }
	for (std::vector<int>::const_iterator cit = pVec->begin(); cit != pVec->end(); ++cit)
	{
		std::cout << "Id: " << *cit << ". Name: " << this->mapSpeaker[*cit].m_name << ". Score: "
				  << this->mapSpeaker[*cit].m_Score[this->round - 1] << std::endl;
	}
}

void SpeechManager::saveRecord()
{
	std::ofstream ofs("../speech.csv", std::ios::out | std::ios::app); // 写文件流
	for (int it : this->vVictory)
	{
		ofs << it << "," << this->mapSpeaker[it].m_Score[1] << ",";
	}
	ofs << std::endl;
	ofs.close();
	std::cout << "Saved record." << std::endl;

	this->emptyFile = false;
}

void SpeechManager::loadRecord()
{
	std::ifstream ifs("../speech.csv", std::ios::in);
	if (!ifs.is_open())
	{
		this->emptyFile = true;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof()) // 读到了文件尾， 文件为空
	{
		ifs.close();
		this->emptyFile = true;
		return;
	}

	this->emptyFile = false; // 文件不为空
	ifs.putback(ch); // 将上面读了的一个字符放回去

	std::string recordStr;
	int ind = 0;

	while (ifs >> recordStr)
	{
		std::cout << recordStr << std::endl;
		std::vector<std::string> lineVec;
		int pos, start = 0;

		while (true)
		{
			pos = recordStr.find(',', start); // 从0开始查找分隔符','
			if (pos == -1) { break; } // 直到找不到， break掉

			// 找到了，进行一行中的每个元素字符串提取，substr参数1：起始位置， 参数2： 长度
			std::string substring = recordStr.substr(start, pos - start);
			lineVec.push_back(substring);
			start = pos + 1; // +1 是跳过','
		}

		this->mapRecord.insert(std::make_pair(ind++, lineVec));
	}
	ifs.close();

	/*
		for (std::map<int, std::vector<std::string>>::const_iterator it = this->mapRecord.begin();
			 it != this->mapRecord.end(); ++it)
		{
			std::cout << "index: " << it->first << ". Winner ID: " << it->second[0] << ". Winner score: " << it->second[1]
					  << std::endl;
		}
	*/
}

void SpeechManager::showRecord()
{
	if (this->emptyFile)
	{
		std::cout << "File is empty or no such file.\n";
		return;
	}

	for (int i = 0; i < this->mapRecord.size(); ++i)
	{
		std::cout << "第" << i + 1 << "届: " << " Winner ID: " << this->mapRecord[i][0] << ". Winner score: "
				  << this->mapRecord[i][1] << std::endl;
	}
}

void SpeechManager::clearRecord()
{
	std::cout << "Clear data? Yes/No" << std::endl;
	char ch;
	std::cin >> ch;

	if ('y' == ch || 'Y' == ch)
	{
		std::ofstream ofs("../speech.csv", std::ios::trunc); // std::ios::trunc 如果存在文件则删除后重新创建
		ofs.close();

		// 初始化属性
		this->initSpeechManager();
		this->createSpeaker();
		this->loadRecord();

		std::cout << "Clear successfully!\n";
	}
	system("clear");
}
