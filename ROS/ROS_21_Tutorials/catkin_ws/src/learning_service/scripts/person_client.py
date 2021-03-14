#!/usr/bin/env python
# -*- coding: utf-8 -*-

# 该例程创建一个Client，并使用自定义的srv类型
import rospy
from learning_service.srv import Person, PersonRequest


def run_person_client():
    rospy.init_node("person_client") # ROS节点初始化
    rospy.wait_for_service("/show_person") # 阻塞，等待/show_person直到发现此service

    try:
        # 创建Client， 服务service名称为/show_person，srv类型为Person
        person_client = rospy.ServiceProxy("/show_person", Person)

        # 请求服务调用，输入请求，获得response
        request = PersonRequest()
        request.name = "Jack"
        request.age = 25
        request.sex = PersonRequest.male
        # 等同于下面的效果
        # response = person_client("Jack", 25, PersonRequest.male)
        response = person_client(request)
        return response.person_serv_result
    except rospy.ServiceException as e:
        print("Error: service call failed: %s" % e)


if __name__ == "__main__":
    ret = run_person_client()
    print("Show person result: %s" % ret)
