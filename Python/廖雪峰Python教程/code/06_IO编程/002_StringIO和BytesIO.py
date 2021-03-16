# -*- coding: utf-8 -*- 
# Created by jackzhang on 02/28/2021
from io import StringIO

# ~~~~~~~~~写~~~~~~~~~~~~~~
f = StringIO()
print(f.write("Hello"))
print(f.write(" "))
print(f.write("World!\n"))

print(f.getvalue())

# ~~~~~~~~~读~~~~~~~~~~~~~
f2 = StringIO("Hello World!\nHello World!\n")
while True:
    line = f2.readline()
    if not line:
        break
    print(line.strip())
