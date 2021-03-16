# -*- coding: utf-8 -*- 
# Created by jackzhang on 02/27/2021

# ~~~~~~~~~example 1. __str__() and __repr__() ~~~~~~~~~
class Student(object):
    def __init__(self, name):
        self.__name = name

    # __str__()方法可以通过print函数作用于类的对象打印
    def __str__(self):
        return "Student object: (name: %s)" % self.__name

    # __repr__()方法是直接调用对象名显示的信息，一般和__str__()方法相同
    __repr__ = __str__


jack = Student("jack")
print(jack)


# ~~~~~~~~~~example 2 __iter__(), __next__() ~~~~~~~~~~~~
# 如果一个类想被用于`for ... in`循环，类似list或tuple那样，就必须实现一个`__iter__()`方法
# 该方法返回一个迭代对象，然后，Python的for循环就会不断调用该迭代对象的`__next__()`方法拿到循环的下一个值
# 直到遇到`StopIteration`错误时退出循环。
class Fib(object):
    def __init__(self):
        self.__num1 = 0
        self.__num2 = 1

    def __iter__(self):
        return self

    def __next__(self):
        self.__num1, self.__num2 = self.__num2, self.__num1 + self.__num2
        if self.__num1 > 1000:
            raise StopIteration()
        return self.__num1


for n in Fib():
    print(n)
print("--------------------------------------")


# ~~~~~~~~~~~~~~~~ example 4: __getitem__() ~~~~~~~~~~~~~~~~~~~~~~~~~~
class Fib2(object):
    def __getitem__(self, item):
        if isinstance(item, int):
            a, b = 1, 1
            for i in range(item):
                a, b = b, a + b
            return a
        if isinstance(item, slice):  # 如果传入的参数是一个切片
            start, stop = item.start, item.stop
            if start is None:
                start = 0
            lst = []
            a, b = 1, 2
            for i in range(start, stop):
                lst.append(a)
                a, b = b, a + b
            return lst


print(Fib2()[3])
print(Fib2()[:3])


# ----------------Example 3: __getattr__()链式调用------------------------
class Chain(object):
    def __init__(self, path=""):
        self.__path = path

    def __getattr__(self, path):
        return Chain("%s/%s" % (self.__path, path))

    def __str__(self):
        return self.__path

    __repr__ = __str__


print(Chain().status.user.timeline.list)


# ----------------Example 4: __call__()-----------------------------
class TestClass(object):
    def __init__(self):
        self.__string = "test string"

    def __call__(self, *args, **kwargs):
        print(self.__string)


TestClass()()
test = TestClass()
test()
# 通过callable函数来判断对象是否能够被调用
print(callable(test))
