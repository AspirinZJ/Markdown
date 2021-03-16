# -*- coding: utf-8 -*- 
# Created by jackzhang on 02/28/2021
import subprocess

print("$ nslookup www.python.org")
ret = subprocess.call(["nslookup", "www.python.org"])
print("Return code: %s" % ret)

# ~~~~~~~~~~~~~控制子进程输入输出~~~~~~~~~~~~~~
print("--------------------------")
print("$ nslookup")
proc = subprocess.Popen(["nslookup"], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
output, err = proc.communicate(b"set q=mx\npython.org\nexit\n")
print(output.decode("utf-8"))
print("Return code: %s" % proc.returncode)
