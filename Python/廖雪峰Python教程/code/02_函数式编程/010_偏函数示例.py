# -*- coding: utf-8 -*- 
# Created by jackzhang on 02/27/2021
import functools

int2 = functools.partial(int, base=2)
print(int2('100'))  # *args = ['100'] **kwargs = {"base": 2}
print(int2('100', base=10))  # 定义了偏函数后仍然可以传入**kwargs

my_max = functools.partial(max, 1000)  # 100会被当作*args传入
print(my_max(2, 5))  # *args = [10, 2, 5], **kwargs ={}
