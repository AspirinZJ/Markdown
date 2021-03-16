# -*- coding: utf-8 -*- 
# Created by jackzhang on 02/28/2021

class MyValueError(ValueError):
    pass


def func(num_str):
    num = int(num_str)

    if 0 == num:
        raise MyValueError("invalid value %s" % num_str)

    return 1 / num


if "__main__" == __name__:
    func(0)
