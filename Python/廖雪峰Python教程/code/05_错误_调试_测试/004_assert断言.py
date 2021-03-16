# -*- coding: utf-8 -*- 
# Created by jackzhang on 02/28/2021

def func(num_str):
    num = int(num_str)
    # 如果assert失败，就会抛出后面的AssertionError
    assert 0 != num, "num is zero!"

    return 1 / num


if "__main__" == __name__:
    func("0")
