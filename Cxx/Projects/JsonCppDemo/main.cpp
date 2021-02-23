#include <iostream>
#include <jsoncpp/json/json.h>
#include <fstream>
#include <sstream>

// 从简单字符串中读取
void readJsonFromStr(const char *str)
{
	Json::Reader reader;
	Json::Value root;

	// 从字符串中读数据
	if (reader.parse(str, root))
	{
		std::string name = root["name"].asString();
		int age = root["age"].asInt();
		std::string sex = root["sex"].asString();

		std::cout << "Name: " << name << ". Age: " << age << ". Sex: " << sex << std::endl;
	}

}

// 从字符串中读取(复杂，多层)
void readJsonFromComStr(std::string &str)
{

	Json::Reader reader;
	Json::Value value;

	// 从字符串中读取数据
	if (reader.parse(str, value))
	{
		// 读取第一层
		std::string name = value["name"].asString();
		std::cout << name << std::endl;

		// 读取第二层
		const Json::Value arrayObj = value["major"];
		for (int i = 0; i < arrayObj.size(); ++i)
		{
			std::string outStr = arrayObj[i]["AI"].asString();
			std::cout << outStr << std::endl;
		}
	}

}

// 读取json文件为string
std::string readStrFromJsonFile(std::string filePath)
{
	std::ifstream ifs(filePath, std::ios::binary);
	std::stringstream buf;
	buf << ifs.rdbuf();
	ifs.close();
	return buf.str();
}

// 从json文件中读取数据
void readJsonFromFile(std::ifstream &ifs)
{
	Json::Reader reader;
	Json::Value value;

	// 从文件中读取
	if (reader.parse(ifs, value))
	{
		// 读取根节点信息
		std::string name = value["name"].asString();
		int age = value["age"].asInt();
		std::string sex = value["sex"].asString();
		std::cout << "Name: " << name << ". Age: " << age << ". Sex: " << sex << std::endl;

		// 读取字节点信息
		std::string friendName = value["friends"]["friend_name"].asString();
		int friendAge = value["friends"]["friend_age"].asInt();
		std::string friendSex = value["friend"]["friend_sex"].asString();
		std::cout << "Friend info: " << friendName << " " << friendAge << " " << friendSex << std::endl;

		// 读取数组信息
		std::cout << "Hobby:\n";
		for (int i = 0; i < value["hobby"].size(); ++i)
		{
			std::string str = value["hobby"][i].asString();
			std::cout << str << " ";
		}
		std::cout << std::endl;
	}
	else { std::cout << "Error: parse error!" << std::endl; }
}

// 写入json文件
void writeJsonFile(std::ofstream &os)
{
	// 根节点
	Json::Value root;

	// 根节点属性
	root["name"] = Json::Value("Jack");
	root["age"] = Json::Value(25);
	root["sex"] = Json::Value("male");

	// 子节点
	Json::Value sub;

	//子节点属性
	sub["friend_name"] = Json::Value("Test");
	sub["friend_sex"] = Json::Value("male");
	sub["friend_age"] = Json::Value(25);

	// 子节点挂载到根节点上
	root["friends"] = Json::Value(sub);

	// 数组形式
	root["hobby"].append("video games");
	root["hobby"].append("anime");
	root["hobby"].append("electronics");

	// 直接输出， 输出到屏幕
	std::cout << "FastWriter\n";
	Json::FastWriter fw;
	std::string jsonStr = fw.write(root);
	std::cout << jsonStr << std::endl;

	// 缩进输出, 输出到屏幕
	std::cout << "StyledWrite: \n";
	Json::StyledWriter sw;
	std::cout << sw.write(root) << std::endl;

	// 输出到文件
	std::string outStr = sw.write(root);
	os << outStr; // os << sw.writer(root);
}

int main()
{
	// 读取json文件为字符串
	std::string jsonStr = readStrFromJsonFile("../sampleJsonFile.json");
	std::cout << jsonStr << std::endl;

	// 从简单字符串中读取
	const char *str = R"({"name":"Jack","age":25,"sex":"male"})";
	readJsonFromStr(str);

	// 从字符串中读取，多层情况
	std::string strValue = R"({"name":"Jack","major":[{"AI":"MachineLearning"},{"AI":"DeepLearning"},{"AI":"ComputerVision"}]})";
	readJsonFromComStr(strValue);

	// 从json文件中读取数据
	std::ifstream ifs("../sampleJsonFile.json", std::ios::binary);
	if (!ifs.is_open())
	{
		std::cout << "Error: cannot open file!" << std::endl;
		return -1;
	}
	readJsonFromFile(ifs);
	ifs.close();

	// 输出到json文件
	std::ofstream os;
	os.open("../writeSample.json", std::ios::out | std::ios::trunc);
	if (!os.is_open()) { std::cout << "Error: cannot open file!\n"; }
	writeJsonFile(os);
	os.close();

	return 0;
}
