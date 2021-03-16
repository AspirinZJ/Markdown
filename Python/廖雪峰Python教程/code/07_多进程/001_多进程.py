# -*- coding: utf-8 -*- 
# Created by jackzhang on 02/28/2021
import os, multiprocessing


def run_proc(proc_name):
    print("Run child process: %s(%s)" % (proc_name, os.getpid()))


if __name__ == "__main__":
    print("Parent pid: %s" % os.getpid())
    pro = multiprocessing.Process(target=run_proc, args=("test_process", ))
    print("Child process will start")
    pro.start()
    pro.join()
    print("Child process end.")
