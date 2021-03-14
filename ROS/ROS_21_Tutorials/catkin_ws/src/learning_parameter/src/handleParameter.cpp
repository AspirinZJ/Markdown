/**
 * @file    handleParameter.cpp
 * @brief   设置/读取ROS参数的例程
 * @details 使用get/set函数来读取/设置ROS参数
 * @author  Jack Zhang
 * @email   zhangmengwei1996@outlook.com
 * @version 1.0.0
 * @date    3/11/21
 * @license GNU General Public License (GPL)
 */
#include <ros/ros.h>
#include <std_srvs/Empty.h>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "handleParameter"); // 初始化ROS节点
	ros::NodeHandle nodeHandle; // 创建节点句柄

	int red, green, blue;

	// 读取背景颜色的参数到变量
	ros::param::get("/turtlesim/background_r", std::ref(red));
	ros::param::get("/turtlesim/background_g", std::ref(green));
	ros::param::get("/turtlesim/background_b", std::ref(blue));
	ROS_INFO("Get background color: [%d, %d, %d]", red, green, blue);

	// 设置背景颜色参数
	ros::param::set("/turtlesim/background_r", 100);
	ros::param::set("/turtlesim/background_g", 100);
	ros::param::set("/turtlesim/background_b", 100);
	ROS_INFO("Set background color: [100, 100, 100 ]");

	// 读取背景颜色的参数到变量
	ros::param::get("/turtlesim/background_r", std::ref(red));
	ros::param::get("/turtlesim/background_g", std::ref(green));
	ros::param::get("/turtlesim/background_b", std::ref(blue));
	ROS_INFO("Get background color: [%d, %d, %d]", red, green, blue);

	ros::service::waitForService("/clear");
	ros::ServiceClient clearBackground = nodeHandle.serviceClient<std_srvs::Empty>("/clear");
	// 调用服务，刷新背景颜色
	std_srvs::Empty srvEmpty;
	clearBackground.call(srvEmpty);

	sleep(1);
	return 0;
}