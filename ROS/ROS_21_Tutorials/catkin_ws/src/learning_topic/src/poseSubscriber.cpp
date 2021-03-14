/**
 * @file    poseSubscriber.cpp
 * @brief   Subscriber示例
 * Details: 创建一个名为poseSubscriber的节点，订阅/turtle1/pose话题，消息类型为turtlesim::Pose
 * @author  jackzhang
 * @email   zhangmengwei1996@outlook.com
 * @version 1.0.0
 * @date    3/10/21
 * @license GNU General Public License (GPL)
 */
#include <ros/ros.h>
#include "turtlesim/Pose.h" // 引入消息类型的头文件

// 接收到订阅的消息后，会进入消息回调函数
void poseCallBack(const turtlesim::Pose::ConstPtr &msg)
{
	ROS_INFO("Turtle Pose: x: %.2f, y: %.2f", msg->x, msg->y); // 打印接受到的消息
}

int main(int argc, char **argv)
{
	// 初始化ROS节点
	ros::init(argc, argv, "poseSubscriber");

	// 创建节点句柄
	ros::NodeHandle nodeHandle;

	// 创建一个Subscriber， 订阅的topic为/turtle1/Pose， 队列长度为10, 回调函数为poseCallBack
	ros::Subscriber poseSubscriber = nodeHandle.subscribe("/turtle1/pose", 10, poseCallBack);

	// 循环等待回调函数
	ros::spin();

	return 0;
}