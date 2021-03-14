#!/usr/bin/env python
# -*- coding: utf-8 -*-
import rospy
from learning_topic.msg import Person


def person_publisher():
    # ROS节点初始化
    rospy.init_node("person_publisher", anonymous=True)

    # 创建一个publisher， 发布topic为/person_info， message类型为Person， 队列长度10
    person_pub = rospy.Publisher("/person_info", Person, queue_size=10)

    # 设置循环频率
    loop_rate = rospy.Rate(10)

    while not rospy.is_shutdown():
        # 创建消息对象
        person_msg = Person()
        person_msg.name = "Jack"
        person_msg.age = 25
        person_msg.sex = 1

        # 发布消息
        person_pub.publish(person_msg)

        # 显示发布的消息
        rospy.loginfo("Published person message: name: %s, age: %d, sex: %d",
                      person_msg.name, person_msg.age, person_msg.sex)

        # 按照设定的循环频率延迟相应的时间
        loop_rate.sleep()


if "__main__" == __name__:
    try:
        person_publisher()
    except rospy.ROSInterruptException:
        pass
