#!/usr/bin/env python
# -*- coding: utf-8 -*-
import rospy
from learning_topic.msg import Person


def person_callback(person_msg):
    rospy.loginfo("Got Person Info: name: %s, age: %d, sex: %d", person_msg.name, person_msg.age, person_msg.sex)


def person_subscriber():
    # 初始化ROS节点
    rospy.init_node("person_subscriber", anonymous=True)

    # 创建Subscriber， topic名称为/person_info， 数据类型为Person， 回调函数为person_callback
    rospy.Subscriber("/person_info", Person, callback=person_callback)

    rospy.spin()


if __name__ == "__main__":
    person_subscriber()
