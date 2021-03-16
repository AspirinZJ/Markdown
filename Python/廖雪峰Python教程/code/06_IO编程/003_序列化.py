# -*- coding: utf-8 -*- 
# Created by jackzhang on 02/28/2021

# ~~~~~~~~~~pickle~~~~~~~~~~~
import pickle
import json

dic1 = {"name": "Jack"}
print(pickle.dumps(dic1))
# dump到文件
with open("./dump.txt", "wb") as f:
    pickle.dump(dic1, f)

with open("./dump.txt", "rb") as f:
    dic2 = pickle.load(f)
    print(dic2)

# ~~~~~~~~~~~~~~json~~~~~~~~~~~~~~
dic3 = {"name": "Jack", "age": 25}
print(json.dumps(dic3))
with open("./dump.json", "w") as f:
    json.dump(dic3, f)

with open("./dump.json", "r") as f:
    dic4 = json.load(f)
    print(dic4)


# 将class dump成json文件或从json文件中读取
class Student(object):
    def __init__(self, name, age, score):
        self.name = name
        self.age = age
        self.score = score


def student2dic(stu):
    return {"name": stu.name, "age": stu.age, "score": stu.score}


def dic2student(dic):
    return Student(dic["name"], dic["age"], dic["score"])


jack = Student("Jack", 25, 100)
stu_str = json.dumps(jack, default=student2dic)  # json dump类时需要指定default转换方法
print(stu_str)
print(json.dumps(jack, default=lambda obj: obj.__dict__))  # 或者直接dump成类的__dict__属性

jack_copy = json.loads(stu_str, object_hook=dic2student)
print(jack_copy.__dict__)
