# -*- coding: utf-8 -*- 
# Created by jackzhang on 02/28/2021
import multiprocessing
import os
import random
import time


def write_pro(que):
    print("Process to write: %s" % os.getpid())
    for value in ['a', 'b', 'c', "ABC", 123]:
        que.put(value)
        time.sleep(random.random() * 3)


def read_pro(que):
    print("Process to read %s" % os.getpid())
    while True:
        value = que.get(True)
        print("read_pro got value: %s" % value)


if __name__ == "__main__":
    queue = multiprocessing.Queue()  # 父进程创建Queue用于通信并传给子进程
    proc_write = multiprocessing.Process(target=write_pro, args=(queue,))
    proc_read = multiprocessing.Process(target=read_pro, args=(queue,))

    proc_write.start()  # 启动用于写入的进程
    proc_read.start()  # 启动用于读取的进程
    proc_write.join()
    proc_read.terminate()  # 由于这个进程是个死循环，无法自动结束，只能终止运行
