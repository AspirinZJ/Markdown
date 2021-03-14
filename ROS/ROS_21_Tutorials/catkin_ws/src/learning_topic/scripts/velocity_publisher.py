#!/usr/bin/env python
# -*- coding: utf-8 -*-

import rospy
from geometry_msgs.msg import Twist


def velocity_publisher():
    # ROS节点初始化
    rospy.init_node("velocity_publisher", anonymous=True)

    # 创建一个Publisher， topic名为/turtle1/cmd_vel， message类型为Twist， 队列长度为10
    turtle_vel_publisher = rospy.Publisher("/turtle1/cmd_vel", Twist, queue_size=10)

    # 循环频率为10
    loop_rate = rospy.Rate(10)

    while not rospy.is_shutdown():
        # 创建消息对象
        vel_msg = Twist()
        vel_msg.linear.x = 0.5
        vel_msg.angular.z = 0.5

        # 发布消息
        turtle_vel_publisher.publish(vel_msg)
        rospy.loginfo("Published turtle velocity command: [%.2f m/s, %.2f rad/s]", vel_msg.linear.x, vel_msg.angular.z)

        # 延迟一段时间
        loop_rate.sleep()


if "__main__" == __name__:
    try:
        velocity_publisher()
    except rospy.ROSInterruptException:
        pass
