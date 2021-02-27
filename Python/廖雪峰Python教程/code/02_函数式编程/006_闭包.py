# example 1
def lazy_sum(*args):
    def my_sum():
        total = 0
        for num in args:
            total += num
        return total

    return my_sum


fun = lazy_sum(1, 2, 3, 4, 5)
print(fun)
ret = fun()
print(ret)


# example 2
def count():
    fun_lst = []
    for i in range(1, 4):
        def f():
            return i

        fun_lst.append(f)
    return fun_lst


f1, f2, f3 = count()
print(f1())  # 3
print(f2())  # 3
print(f3())  # 3


# example3 获取循环变量
def count():
    def g(j):
        def f():
            return j

        return f

    fun_lst = []
    for i in range(1, 4):
        fun_lst.append(g(i))
    return fun_lst


f1, f2, f3 = count()
print(f1())  # 1
print(f2())  # 2
print(f3())  # 3
