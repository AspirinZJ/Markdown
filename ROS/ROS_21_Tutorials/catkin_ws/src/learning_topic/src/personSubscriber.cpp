/**
 * @file    personSubscriber.cpp.c
 * @brief   Subscriber
 * Details: 
 * @author  jackzhang
 * @email   zhangmengwei1996@outlook.com
 * @version 1.0.0
 * @date    3/10/21
 * @license GNU General Public License (GPL)
 */
#include <ros/ros.h>
#include "learning_topic/Person.h"

void personCallback(const learning_topic::Person::ConstPtr &personMsg)
{
	ROS_INFO("Got Person Info: name: %s, age: %d, sex: %d",
			 personMsg->name.c_str(), personMsg->age, personMsg->sex);
}

int main(int argc, char **argv)
{
	// 初始化ROS节点
	ros::init(argc, argv, "personSubscriber");

	ros::NodeHandle nodeHandle;

	// 创建一个节点，订阅的topic为/person_info，队列长度10, 回调函数是personCallback
	ros::Subscriber personSubscriber = nodeHandle.subscribe("/person_info", 10, personCallback);

	// 循环等待回调函数
	ros::spin();

	return 0;
}