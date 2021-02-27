# -*- coding: utf-8 -*- 
# Created by jackzhang on 02/27/2021

"""@property负责将一个方法变成属性调用，同时也可以为之生成一个@属性.setter"""


class Student(object):
    def __init__(self, name, age):
        self.__name = name
        self.__age = age

    @property  # 将getter方法装饰成属性, 由于没有setter， 所以是只读
    def name(self):
        return self.__name

    @property  # 将getter方法装饰成属性, 由于有setter， 所以是读写
    def age(self):
        return self.__age

    @age.setter  # setter， 可以提供输入检查效果
    def age(self, age):
        if not isinstance(age, int):
            raise TypeError("age must be an integer!")
        if age < 0 or age > 100:
            raise ValueError("age must be within [0, 100]!")
        self.__age = age


if "__main__" == __name__:
    jack = Student("Jack", 24)
    jack.age = 25  # setter
    print("Name: {}, Age: {}".format(jack.name, jack.age))  # getter

    bob = Student("Bob", 25)
    bob.age = "25"
