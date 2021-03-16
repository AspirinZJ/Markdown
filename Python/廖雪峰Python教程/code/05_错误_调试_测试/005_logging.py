# -*- coding: utf-8 -*- 
# Created by jackzhang on 02/28/2021
import logging

logging.basicConfig(level=logging.DEBUG)
# logging.basicConfig(level=logging.ERROR)

if "__main__" == __name__:
    num = int("0")
    logging.info("num = %d" % num)
    print(1 / num)
