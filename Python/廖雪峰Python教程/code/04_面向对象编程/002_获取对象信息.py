# -*- coding: utf-8 -*- 
# Created by jackzhang on 02/27/2021

# 1. 使用type()
import types  # 使用其中的FunctionType, BuiltinFunctionType, LambdaType, GeneratorType...


class MyClass(object):
    pass


print(type(123))
print(type("123"))
print(type(None))
print(type(abs))
my_class = MyClass()
print(type(my_class))
print(type(lambda x: x) == types.LambdaType)
print("----------------")

# 2. 使用isinstance()
print(isinstance(my_class, MyClass))
print(isinstance(123, int))

# 可以判断一个变量是否是某些类型之中的一种
print(isinstance((x for x in range(1, 4, 1)), (list, types.GeneratorType)))
print("----------------")

# 3. 使用dir()获取一个对象的所有属性和方法
print(dir(str))
print(dir("123"))
print("----------------")


# 配合getattr(), setattr(), hasattr()直接操作一个对象的状态
class MyObject(object):
    def __init__(self):
        self.x = 1

    def power(self):
        return self.x * self.x


obj = MyObject()
# hasattr()
print("has x? {} has y? {} has power? {}".format(hasattr(obj, "x"), hasattr(obj, "y"), hasattr(obj, "power")))
# setattr()
setattr(obj, "y", 10)
print("has x? {} has y? {}".format(hasattr(obj, "x"), hasattr(obj, "y")))
# getattr()可以传入一个默认参数，不过不存在就返回默认参数
print(getattr(obj, "y"))
print(getattr(obj, "z", 404))
power = getattr(obj, "power")
print(power())
