# 利用map和reduce编写一个str2float函数，把字符串'123.456'转换成浮点数123.456
from functools import reduce

# 字符转换成数字的字典
str2num_dic = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9}


def str2float(string):
    integer, fractional = string.split('.')

    def str2digit(char):
        return str2num_dic[char]

    integer = reduce(lambda x, y: 10 * x + y, map(str2digit, integer))  # 整数部分
    fractional = reduce(lambda x, y: 10 * x + y, map(str2digit, fractional)) / pow(10, len(fractional))  # 小数部分

    return integer + fractional


if __name__ == "__main__":
    input_str = "123.456"
    print(str2float(input_str))
