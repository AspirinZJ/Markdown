# -*- coding: utf-8 -*- 
# Created by jackzhang on 02/28/2021

with open("./test.txt", 'r') as f:
    for line in f.readlines():
        print(line.strip())  # strip()去除后面的\n

print("---------------------------")

with open("./test.txt", 'r') as f:
    print(f.readline().strip())
    print(f.readline().strip())
    print(f.readline().strip())

print("---------------------------")

with open("./test.txt", "r") as f:
    print(f.read())

# ~~~~~~~~~写文件~~~~~~~~~~~~~~~
with open("./out.txt", "w") as f:
    f.write("test line 1\n")
    f.write("test line 2\n")
