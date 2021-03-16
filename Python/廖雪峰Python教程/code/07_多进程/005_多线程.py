# -*- coding: utf-8 -*- 
# Created by jackzhang on 02/28/2021
import threading
import time


def loop():
    print("Thread %s is running...." % threading.current_thread().name)
    for i in range(5):
        print("Thread %s is running the %s th times..." % (threading.current_thread().name, i))
        time.sleep(1)
    print("Thread %s ended." % threading.current_thread().name)


if __name__ == "__main__":
    print("Thread %s is running" % threading.current_thread().name)
    t = threading.Thread(target=loop, name="LoopThread")
    t.start()
    t.join()
    print("Thread %s ended." % threading.current_thread().name)
