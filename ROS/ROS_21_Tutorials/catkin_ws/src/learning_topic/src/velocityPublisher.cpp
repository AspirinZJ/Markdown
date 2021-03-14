/**
 * @file    velocityPublisher.cpp
 * @brief	简单的ROS Publisher示例
 * Details: 创建一个Publisher，发布topic为/turtle1/cmd_vel， 发布的消息类型为geometry_msgs::Twist
 * @author  jackzhang
 * @email   zhangmengwei1996@outlook.com
 * @version 1.0.0
 * @date    3/10/21
 * @license GNU General Public License (GPL)
 */

#include <ros/ros.h>
// 包含相关message的头文件
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv)
{
	// ROS节点初始化，第三个参数是节点名称
	ros::init(argc, argv, "velocityPublisher");

	/// 创建节点句柄，用于管理节点资源
	ros::NodeHandle nodeHandle;

	/// 创建一个Publisher， 消息类型为geometry_msgs:Twist第一个参数是topic name， 第二个参数是queue长度
	ros::Publisher velocityPublisher = nodeHandle.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

	// 设置循环的频率
	ros::Rate loopRate(10);

	while (ros::ok())
	{
		// 创建消息对象
		geometry_msgs::Twist velMsg;
		velMsg.linear.x = 0.5;
		velMsg.angular.z = 0.1;

		// 发布message
		velocityPublisher.publish(velMsg);
		ROS_INFO("Published turtle velocity command [%.2f m/s %.2f rad/s]\n", velMsg.linear.x, velMsg.angular.z);

		// 按照设定的频率延时
		loopRate.sleep();
	}

	return 0;
}

