# -*- coding: utf-8 -*- 
# Created by jackzhang on 02/27/2021
import types


class Class1(object):
    pass


# 可以给实例绑定属性或方法
c1 = Class1()
c1.string = "123"
print("c1.string: {}".format(c1.string))


def set_string(self, string):
    self.string = string


c1.set_string = types.MethodType(set_string, c1)  # 给实例绑定方法
c1.set_string("456")
print("c1.string: {}".format(c1.string))

c11 = Class1()
Class1.set_string = set_string  # 给类绑定方法，对所有的示例都起作用
c11.set_string("123")
print("c11.string: {}".format(c11.string))


# ~~~~~~~~~~~~~使用slots限制动态绑定的属性~~~~~~~~~~~~~
class Class2(object):
    __slots__ = {"name", "age"}


c2 = Class2()
c2.name = "Jack"
c2.sex = "male" # =>不在__slots__中，会报错
