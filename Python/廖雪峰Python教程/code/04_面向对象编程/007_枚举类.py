# -*- coding: utf-8 -*- 
# Created by jackzhang on 02/27/2021

# --------------------Example 1: Enum---------------------
from enum import Enum, unique

# Enum枚举类型
Weekday = Enum("Weekday", ("Sun", "Mon", "Tue", "Wed", "Thur", "Fri", "Sat"))
print(Weekday.Sun)
# 遍历枚举成员
for name, member in Weekday.__members__.items():
    print(name, "=>", member, ',', member.value)
print("----------------------------------------------")


@unique  # unique装饰器用于检查是否有重复值
class Month(Enum):
    Jan = 1
    Feb = 2
    Mar = 3
    Apr = 4
    May = 5
    June = 6
    July = 7
    Aug = 8
    Sep = 9
    Oct = 10
    Nov = 11
    Dec = 12


# 访问枚举类型
mon1 = Month.Jan
print(mon1)
print(Month.Feb)
print(Month["Feb"])
print(Month.Feb.value)
print(Month(1))

for name, member in Month.__members__.items():
    print(name, "=>", member, ": ", member.value)
