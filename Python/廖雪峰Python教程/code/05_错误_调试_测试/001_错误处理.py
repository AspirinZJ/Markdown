# -*- coding: utf-8 -*- 
# Created by jackzhang on 02/28/2021

# ~~~~~~~~~~~~~~~~Example 1~~~~~~~~~~~~~~~~~~~~~~
try:
    print("try...")
    # result = 10 / 0
    result2 = 10 / int('a')
except ZeroDivisionError as e:
    print("Error: %s" % e)
except TypeError as e:
    print("Error: %s" % e)
except ValueError as e:
    print("Error: %s" % e)
else:
    print("No error.")
finally:
    print("finally...")


# ~~~~~~~~~~~~~~~~Example 2~~~~~~~~~~~~~~~~~~~~~~~~
# 可以跨越多层调用，比如函数main()调用bar()，bar()调用foo()，结果foo()出错了
# 只要main()捕获到了，就可以处理
def foo(s):
    return 10 / int(s)


def bar(s):
    return foo(s) * 2


def main():
    try:
        bar('0')
    except Exception as e:
        print('Error:', e)
    finally:
        print('finally...')
