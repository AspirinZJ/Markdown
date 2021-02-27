# -*- coding: utf-8 -*-
# Created by jackzhang on 02/27/2021

import functools


# ------------Example 1, 简单的装饰器-------------
# decorator
def log(func):
    @functools.wraps(func)
    def wrapper(*args, **kw):
        print("call %s():" % func.__name__)
        # return func(*args, **kw)  # 注意，返回的时候会调用一下func
        func(*args, **kw)

    return wrapper


# 用@将decorator放置在函数顶部
@log  # => now = log(now)
def now():
    print("now")


now()  # => log(now)()
print("now.__name__: %s" % now.__name__)


# ------------Example 2, 传入参数的装饰器-------------
def log2(text):
    def decorator(func):
        @functools.wraps(func)
        def wrapper(*args, **kw):
            print("%s %s()" % (text, func.__name__))
            func(*args, **kw)
            print("end call")

        return wrapper

    return decorator


@log2("execute:")  # => now2 = log2('execute')(now2)
def now2():
    print("now")


now2()  # => log2('execute')(now2)()
print("now2.__name__: %s" % now2.__name__)
