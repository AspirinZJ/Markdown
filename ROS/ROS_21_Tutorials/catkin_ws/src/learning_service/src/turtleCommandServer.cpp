/**
 * @file    turtleCommandServer.cpp
 * @brief   
 * Details: 
 * @author  Jack Zhang
 * @email   zhangmengwei1996@outlook.com
 * @version 1.0.0
 * @date    3/10/21
 * @license GNU General Public License (GPL)
 */
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_srvs/Trigger.h>

bool pubCommand = false; // 用于记录Trigger信息, 为真的话发布海龟运动的速度信息

bool commandCallback(std_srvs::Trigger::Request &request, std_srvs::Trigger::Response &response);

int main(int argc, char **argv)
{
	// 初始化节点
	ros::init(argc, argv, "turtleCommandServer");

	// 创建节点句柄
	ros::NodeHandle nodeHandle;

	// 创建一个Server， service名为/turtle_command， 注册回调函数
	ros::ServiceServer commandServer = nodeHandle.advertiseService("/turtle_command", commandCallback);

	// 创建一个Publisher， topic名称为/turtle1/cmd_vel， 队列长度为10
	ros::Publisher turtleVelPublisher = nodeHandle.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

	// 设置循环频率
	ros::Rate loopRate(10);

	while (ros::ok())
	{
		// 查看一次回调函数队列
		ros::spinOnce();
		if (pubCommand) // 如果pubCommand为真则发布海龟运动的信息
		{
			geometry_msgs::Twist velMsg;
			velMsg.linear.x = 0.5;
			velMsg.angular.z = 0.5;
			turtleVelPublisher.publish(velMsg);
		}
		loopRate.sleep(); // 按照设定好的循环频率延时
	}

	return 0;
}

/**
 * @brief 用于注册到service的回调函数
 * @param request 向server的请求
 * @param response server的回应
 * @return server处理是否成功
 */
bool commandCallback(std_srvs::Trigger::Request &request, std_srvs::Trigger::Response &response)
{
	pubCommand = !pubCommand;

	ROS_INFO("Publish turtle velocity command [%s]", true == pubCommand ? "Yes" : "No");

	// 设置反馈数据
	response.success = true;
	response.message = "Change turtle command state!";

	return true;
}
