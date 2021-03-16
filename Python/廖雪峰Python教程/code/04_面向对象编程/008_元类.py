# -*- coding: utf-8 -*- 
# Created by jackzhang on 02/27/2021

# ----------Example 1: type()创建类---------------------
def fun(self, name):
    print("Hello {}!".format(name))


Hello = type("Hello", (object,), dict(hello=fun))
h = Hello()
h.hello("Jack")
print(type(Hello))
print(type(h))


# ---------Example 2: metaclass 元类-------------------
class ListMetaclass(type):
    def __new__(mcs, name, bases, attrs):
        print("mcs: %s, name: %s, bases: %s, attrs: %s" % (mcs, name, bases, attrs))
        attrs["add"] = lambda self, value: self.append(value)
        return type.__new__(mcs, name, bases, attrs)


class MyList(list, metaclass=ListMetaclass):
    pass


lst = MyList()
lst.add(1)
print(lst)
