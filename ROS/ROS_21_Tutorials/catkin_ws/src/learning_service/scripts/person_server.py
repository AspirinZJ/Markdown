#!/usr/bin/env python
# -*- coding: utf-8 -*-

# 该例程执行/show_person服务，srv类型为learning_service::Person
import rospy
from learning_service.srv import Person, PersonResponse


def person_callback(req):
    rospy.loginfo("Person name: %s age: %d sex: %d", req.name, req.age, req.sex)

    # 反馈数据
    return PersonResponse("OK")


def run_person_server():
    rospy.init_node("run_person_server")  # 初始化ROS节点
    rospy.Service("/show_person", Person, person_callback)  # 创建Server，服务名/show_person，类型Person，并注册回调函数
    print("Ready to show person info...")

    # 循环等待回调函数
    rospy.spin()


if __name__ == '__main__':
    run_person_server()
