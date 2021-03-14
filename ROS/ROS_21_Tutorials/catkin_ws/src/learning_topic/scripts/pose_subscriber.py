#!/usr/bin/env python
# -*- coding: utf-8 -*-
import rospy
from turtlesim.msg import Pose


def pose_callback(msg):
    rospy.loginfo("Turtle pose: x: %.2f, y: %.2f", msg.x, msg.y)


def pose_subscriber():
    # ROS节点初始化
    rospy.init_node("pose_subscriber", anonymous=True)

    # 创建一个Subscriber，订阅topic为/turtle1/pose，message类型为Pose, 处理消息的回调函数为pose_callback
    rospy.Subscriber("/turtle1/pose", Pose, callback=pose_callback)

    # 循环等待回调函数
    rospy.spin()


if "__main__" == __name__:
    pose_subscriber()
