# -*- coding: utf-8 -*- 
# Created by jackzhang on 02/28/2021
import logging


def foo(num):
    return 1 / num


def bar(num):
    return foo(num) * 2


def main():
    try:
        bar(0)
    except Exception as e:
        logging.exception(e)


if "__main__" == __name__:
    main()
    # 程序在打印出错误后会继续执行，然后正常退出
    print("program ends")
