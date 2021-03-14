/**
 * @file    personServer.cpp.c
 * @brief   自定义服务类型srv的Server编程实现
 * Details: 服务名称为/show_person， srv类型为learning_service::Person
 * @author  Jack Zhang
 * @email   zhangmengwei1996@outlook.com
 * @version 1.0.0
 * @date    3/11/21
 * @license GNU General Public License (GPL)
 */
#include <ros/ros.h>
#include "learning_service/Person.h"

bool personServCallback(learning_service::Person::Request &req, learning_service::Person::Response &res);

int main(int argc, char **argv)
{
	ros::init(argc, argv, "personServer"); // 初始化ROS节点
	ros::NodeHandle nodeHandle; // 创建节点句柄

	// 创建Server, 名称为/show_person， 并注册回调函数
	ros::ServiceServer personServer = nodeHandle.advertiseService("/show_person", personServCallback);
	ROS_INFO("Ready to show person info...");

	// 循环等待回调函数
	ros::spin();

	return 0;
}

/**
 * @brief /show_person服务的回调函数
 * @param req 服务请求
 * @param res 服务答复
 * @return 是否调用服务成功
 */
bool personServCallback(learning_service::Person::Request &req, learning_service::Person::Response &res)
{
	ROS_INFO("Request: Person name: %s, age: %d, sex: %d", req.name.c_str(), req.age, req.sex);

	// 发送反馈数据
	res.person_serv_result= "OK";

	return true;
}
