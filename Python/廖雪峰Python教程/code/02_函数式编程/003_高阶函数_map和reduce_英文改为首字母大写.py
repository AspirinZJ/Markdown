# 利用map()函数，把用户输入的不规范的英文名字，变为首字母大写，其他小写的规范名字。
# 输入：['adam', 'LISA', 'barT']，输出：['Adam', 'Lisa', 'Bart']
def normalize(name_str):
    def to_camel_case(string):
        if len(string) <= 1:
            return string

        return string[0].upper() + string[1:].lower()

    return map(to_camel_case, name_str)


if __name__ == "__main__":
    str_lst = ['adam', 'LISA', 'barT']
    str_lst_out = normalize(str_lst)
    print(list(str_lst_out))
