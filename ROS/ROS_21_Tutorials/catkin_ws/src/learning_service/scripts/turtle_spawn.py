#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Client 示例代码
import rospy
from turtlesim.srv import Spawn


def turtle_spawn():
    # 初始化ROS节点
    rospy.init_node("turtle_spawn", anonymous=True)

    # 阻塞，一直等待直到连接到/spawn服务
    rospy.wait_for_service("/spawn")

    try:
        # 创建Client， 连接的service为/spawn， 服务类型为Spawn
        add_turtle = rospy.ServiceProxy("/spawn", Spawn)
        # 请求服务调用，输入请求数据
        response = add_turtle(2.0, 2.0, 0.0, "turtle2")
        return response.name
    except rospy.ServiceException as e:
        print("Service call failed: %s", e)


if __name__ == "__main__":
    ret = turtle_spawn()
    print("Spawn turtle successfully! name: %s" % ret)
