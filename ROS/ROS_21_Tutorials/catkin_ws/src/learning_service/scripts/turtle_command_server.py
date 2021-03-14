#!/usr/bin/env python
# -*- coding: utf-8 -*-

# service Server的编程实现
# 该示例将执行/turtle_command service，service类型为std_srvs/Trigger
import rospy
from geometry_msgs.msg import Twist
from std_srvs.srv import Trigger, TriggerResponse
import threading
import time

pub_command = False


def command_thread():
    # 创建一个Publisher用于想/turtle1/cmd_vel 发送类型为Twist的message
    turtle_vel_publisher = rospy.Publisher("/turtle1/cmd_vel", Twist, queue_size=10)
    # 创建Twist对象向/turtle1/cmd_vel发送message
    vel_msg = Twist()
    vel_msg.linear.x = 0.5
    vel_msg.angular.z = 0.5
    while True:
        if pub_command:
            turtle_vel_publisher.publish(vel_msg)
        time.sleep(0.1)


def command_callback(req):
    print("request is: %s" % req)
    global pub_command
    pub_command = not pub_command
    rospy.loginfo("Publish turtle velocity command! [%d]", pub_command)

    # 反馈数据
    return TriggerResponse(True, "Change turtle command state!")


def turtle_command_server():
    # ROS节点初始化
    rospy.init_node("turtle_command_server")

    rospy.Service("/turtle_command", Trigger, command_callback)
    print("Ready to receive turtle command...")

    th = threading.Thread(target=command_thread, name="command_thread", args=())
    th.start()

    # 在python的ROS接口里没有spinOnce实现，所以需要多线程
    # 循环等待回调函数
    rospy.spin()


if __name__ == '__main__':
    turtle_command_server()
