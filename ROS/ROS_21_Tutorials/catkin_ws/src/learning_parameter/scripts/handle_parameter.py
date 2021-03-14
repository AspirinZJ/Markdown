#!/usr/bin/env python
# -*- coding: utf-8 -*-

# 该例程设置/读取ROS参数
import rospy
from std_srvs.srv import Empty
import random


def handle_parameter():
    rospy.init_node("handle_parameter")  # ROS节点初始化

    # 读取背景颜色参数
    red = rospy.get_param("/turtlesim/background_r")
    green = rospy.get_param("/turtlesim/background_g")
    blue = rospy.get_param("/turtlesim/background_b")
    rospy.loginfo("Got turtlesim background color: [{}, {}, {}]".format(red, green, blue))

    # 设置背景颜色参数
    rand_color = int(random.random() * 255)
    rospy.set_param("/turtlesim/background_r", rand_color)
    rospy.set_param("/turtlesim/background_g", rand_color)
    rospy.set_param("/turtlesim/background_b", rand_color)
    rospy.loginfo("Set turtlesim background color: [{}, {}, {}]".format(rand_color, rand_color, rand_color))

    # 读取背景颜色参数
    red = rospy.get_param("/turtlesim/background_r")
    green = rospy.get_param("/turtlesim/background_g")
    blue = rospy.get_param("/turtlesim/background_b")
    rospy.loginfo("Got turtlesim background color: [{}, {}, {}]".format(red, green, blue))

    # 阻塞，等待直到发现/clear服务
    rospy.wait_for_service("/clear")

    try:
        clear_background = rospy.ServiceProxy("/clear", Empty)
        response = clear_background()
        return response
    except rospy.ServiceException as e:
        print("Service call failed: %s" % e)


if __name__ == "__main__":
    handle_parameter()
