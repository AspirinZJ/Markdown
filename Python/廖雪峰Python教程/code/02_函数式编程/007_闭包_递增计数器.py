# 利用闭包返回一个计数器函数，每次调用它返回递增整数

# 方法1 利用nonlocal关键字
def create_counter():
    cnt = 0

    def counter():
        # nonlocal关键字用来在函数或其他作用域中使用外层(非全局)变量。
        # 如果在内部函数中只是仅仅读外部变量，可以不在此变量前加nonlocal
        # 如果在内部函数中尝试进行修改外部变量，且外部变量为不可变类型，则需要在变量前加nonlocal，如果变量为可变类型，则不需要添加nonlocal
        # 利用nonlocal关键字声明变量cnt，既不是局部变量，也不是全局变量，需要向上一层变量空间找这个变量。只在闭包里面生效，只能用在嵌套函数中
        nonlocal cnt
        cnt += 1
        return cnt

    return counter


# 方法2 利用可变数据类型list

def create_counter2():
    lst = [0]  # 初始化列表L为0

    def counter():
        lst[0] += 1  # L[0]指的是列表L的第一个元素，为一个可变变量
        return lst[0]

    return counter


# 方法3 利用生成器
def create_counter3():
    def generator():
        num = 0
        while True:
            num += 1
            yield num

    gen = generator()

    def counter():
        return next(gen)

    return counter


if __name__ == "__main__":
    counterA = create_counter3()
    print(counterA(), counterA(), counterA(), counterA(), counterA())  # 1 2 3 4 5
    counterB = create_counter3()
    if [counterB(), counterB(), counterB(), counterB()] == [1, 2, 3, 4]:
        print('测试通过!')
    else:
        print('测试失败!')
