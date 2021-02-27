# -*- coding: utf-8 -*- 
# Created by jackzhang on 02/27/2021

# 类属性以__开头的是私有成员
class Student(object):
    def __init__(self, name, gender):
        self.__name = name
        self.__gender = gender

    def get_name(self):
        return self.__name

    def get_gender(self):
        return self.__gender

    def set_name(self, name):
        self.__name = name

    def set_gender(self, gender):
        if "male" == gender or "female" == gender:
            self.__gender = gender
        else:
            raise ValueError("invalid gender")


if __name__ == "__main__":
    bart = Student('Bart', 'male')
    if bart.get_gender() != 'male':
        print('测试失败!')
    else:
        bart.set_gender('female')
        if bart.get_gender() != 'female':
            print('测试失败!')
        else:
            print('测试成功!')

    jack = Student("Jack", "male")
    # jack.set_gender("god")
