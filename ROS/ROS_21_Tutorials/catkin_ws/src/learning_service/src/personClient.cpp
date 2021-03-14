/**
 * @file    personClient.cpp.c
 * @brief   自定义server Client编程实现
 * @details	节点名称：personClient， service名称: /show_person， srv类型: learning_service::Person
 * @author  Jack Zhang
 * @email   zhangmengwei1996@outlook.com
 * @version 1.0.0
 * @date    3/11/21
 * @license GNU General Public License (GPL)
 */
#include <ros/ros.h>
#include <learning_service/Person.h>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "personClient"); // 初始化ROS节点
	ros::NodeHandle nodeHandle; // 创建节点句柄

	// 等待/show_person服务，阻塞直到发现服务
	ros::service::waitForService("/show_person");

	// 创建Service Client，service名称为/show_person， srv类型为learning_service::Person
	ros::ServiceClient personClient = nodeHandle.serviceClient<learning_service::Person>("/show_person");

	// 初始化service的请求数据
	learning_service::Person srv;
	srv.request.name = "Jack";
	srv.request.age = 25;
	srv.request.sex = learning_service::Person::Request::male;
	ROS_INFO("Call service to show person [name: %s, age: %d, sex: %d]",
			 srv.request.name.c_str(), srv.request.age, srv.request.sex);

	// 请求服务调用
	personClient.call(srv);

	ROS_INFO("Show person result: %s", srv.response.person_serv_result.c_str());

	return 0;
}
