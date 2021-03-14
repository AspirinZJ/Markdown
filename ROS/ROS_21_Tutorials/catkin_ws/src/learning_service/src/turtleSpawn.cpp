/**
 * @file    turtleSpawn.cpp
 * @brief   Service Client示例
 * Details: 创建一个Client，连接的服务是/spawn
 * @author  Jack Zhang
 * @email   zhangmengwei1996@outlook.com
 * @version 1.0.0
 * @date    3/10/21
 * @license GNU General Public License (GPL)
 */
#include <ros/ros.h>
#include <turtlesim/Spawn.h> // 包含服务的头文件

int main(int argc, char **argv)
{
	// 初始化ROS节点
	ros::init(argc, argv, "turtleSpawn");

	// 创建节点句柄
	ros::NodeHandle nodeHandle;

	// 阻塞，等待发现/spawn服务
	ros::service::waitForService("/spawn");

	// 上一步代码通过后，创建一个Client， 连接的service是/spawn
	ros::ServiceClient addTurtle = nodeHandle.serviceClient<turtlesim::Spawn>("/spawn");

	// 创建turtlesim::Spawn类型的服务请求数据
	turtlesim::Spawn srv;
	srv.request.x = 3.0;
	srv.request.y = 3.0;
	srv.request.name = "turtle2";
	ROS_INFO("Call service to spawn turtle [x: %.2f, y: %.2f, name: %s]",
			 srv.request.x, srv.request.y, srv.request.name.c_str());

	// 阻塞，请求服务调用， 等待Server的反馈后才会往下运行
	addTurtle.call(srv);

	// 显示服务调用结果
	ROS_INFO("Spawn turtle successfully! [name: %s]", srv.response.name.c_str());

	return 0;
}
