# -*- coding: utf-8 -*- 
# Created by jackzhang on 02/27/2021
import functools
import time


def metric(fn):
    @functools.wraps(fn)
    def wrapper(*args, **kwargs):
        start = time.time()
        ret = fn(*args, **kwargs)
        print('%s executed in %s ms' % (fn.__name__, time.time() - start))
        return ret

    return wrapper


@metric
def fast(x, y):
    time.sleep(0.0012)
    return x + y;


@metric
def slow(x, y, z):
    time.sleep(0.1234)
    return x * y * z;


f = fast(11, 22)
s = slow(11, 22, 33)
if f != 33:
    print('测试失败!')
elif s != 7986:
    print('测试失败!')
