/**
 * @file    personPublisher.cpp.c
 * @brief   创建一个Publisher，发布自定义的数据类型
 * Details: 发布的topic为/person_info，队列长度10
 * 消息类型为learning_topic::Person, 定义在learning_topic/msg/Person.msg中
 * @author  jackzhang
 * @email   zhangmengwei1996@outlook.com
 * @version 1.0.0
 * @date    3/10/21
 * @license GNU General Public License (GPL)
 */
#include <ros/ros.h>
#include "learning_topic/Person.h"

int main(int argc, char **argv)
{
	// 初始化ROS节点
	ros::init(argc, argv, "personPublisher");

	// 创建节点句柄
	ros::NodeHandle nodeHandle;

	// 创建Publisher， 发布的topic名称为/person_info，message类型为learning_topic下的Person， 队列长度10
	ros::Publisher personPublisher = nodeHandle.advertise<learning_topic::Person>("/person_info", 10);

	// 设置循环频率
	ros::Rate loopRate(10);

	while (ros::ok())
	{
		// 创建learning_topic::Person类型的数据信息
		learning_topic::Person personMsg;
		personMsg.name = "Jack";
		personMsg.age = 25;
		personMsg.sex = learning_topic::Person::male;

		// 发布消息
		personPublisher.publish(personMsg);

		ROS_INFO("Published Person Info: name: %s, age: %d, sex: %d",
				 personMsg.name.c_str(), personMsg.age, personMsg.sex);

		// 按照设定的循环频率延时
		loopRate.sleep();
	}


	return 0;
}

