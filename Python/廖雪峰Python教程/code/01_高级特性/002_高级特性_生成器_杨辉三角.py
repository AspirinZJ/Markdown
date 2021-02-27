"""
杨辉三角定义如下：

          1
         / \
        1   1
       / \ / \
      1   2   1
     / \ / \ / \
    1   3   3   1
   / \ / \ / \ / \
  1   4   6   4   1
 / \ / \ / \ / \ / \
1   5   10  10  5   1
把每一行看做一个list，试写一个generator，不断输出下一行的list：
"""


def triangle_generator():
    lst = [1]
    while True:
        yield lst
        lst = [lst[i - 1] + lst[i] if i >= 1 else lst[i] for i in range(len(lst))]
        lst.append(1)


def triangle_generator2():
    lst = [1]
    while True:
        yield lst
        lst.insert(0, 0)  # 最前面插入0
        lst.append(0)  # 最后面插入0
        lst = [lst[i] + lst[i + 1] for i in range(len(lst) - 1)]


if __name__ == '__main__':
    n = 0
    for t in triangle_generator2():
        print(t)
        n += 1
        if n >= 10:
            break
