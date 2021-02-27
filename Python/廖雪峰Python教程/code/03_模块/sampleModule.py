# -*- coding: utf-8 -*- 
# Created by jackzhang on 02/27/2021


"""自定义模块示例"""

__author__ = "Jack Zhang"

import sys  # 使用sys.argv获得命令行输入信息


def greeting():
    args = sys.argv
    if 1 == len(args):
        print("Hello!")
    elif 2 == len(args):
        print("Hello {}!".format(args[1]))
    else:
        print("Too many arguments.")


if __name__ == "__main__":
    greeting()
