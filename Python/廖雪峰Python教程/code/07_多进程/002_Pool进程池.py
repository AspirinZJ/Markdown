# -*- coding: utf-8 -*- 
# Created by jackzhang on 02/28/2021
import multiprocessing, random, os, time


def run_proc(name):
    print("Run task %s(%s)" % (name, os.getpid()))
    start = time.time()
    time.sleep(random.random() * 3)
    end = time.time()
    print("Task %s runs %.2f seconds." % (name, end - start))


if __name__ == "__main__":
    print("Parent process %s." % os.getpid())
    pool = multiprocessing.Pool(7)
    for i in range(8):
        pool.apply_async(run_proc, args=(i, ))
    print("Waiting for all subprocesses done.")
    pool.close()
    pool.join()
    print("All subprocesses done.")
