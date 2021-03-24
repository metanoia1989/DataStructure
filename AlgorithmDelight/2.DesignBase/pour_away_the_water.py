#!/usr/bin/env python3
#-*- coding: utf-8 -*-

"""
穷举搜索寻找最优解的倒水问题    
用三个容积分别为 3升、8升和 5升的水桶如何获得 4升水的问题。
将三个水桶中当前的水量定义为一个状态，将倒水定义为一个驱动状态转换的动作，则这个问题就转换为水桶状态的穷举搜索问题。
在解空间中用穷举的方法遍历所有可能的解，并找到最终合法的解是解决最优解问题的常用数学模型。  
"""

from __future__ import annotations


class Bucket():
    """
    水桶
    """
    def __init__(self, capacity, water = 0) -> None:
        self.capacity = capacity
        self.water = water

    def setWater(self, water):
        if water > self.capacity:
            water = self.capacity
        self.water = water
        
    def getWater(self):
        return self.water
    
    def receiveWaterSize(self):
        """
        能接受的水量
        """
        return self.capacity - self.water
    
    def receiveWater(self, water):
        """
        接入新的水
        """
        if (water > self.receiveWaterSize()):
            raise Exception("could't receive so many water")

        self.water += water
    
    def transform(self, buket : Bucket):
        """
        将水装入另外的水桶中    
        """
        if self.water == 0:
            return

        if self.water <= buket.receiveWaterSize():
            buket.receiveWater(self.water)
            self.water = 0 
        else:
            self.water -= buket.receiveWaterSize()
            buket.receiveWater(buket.receiveWaterSize())


def pour_water_find():
    """
    倒水方案查询
    用三个容积分别为 3升、8升和 5升的水桶如何获得 4升水的问题。
    """
    bucket_3 = Bucket(3)
    bucket_8 = Bucket(8)
    bucket_5 = Bucket(5)
    
    # 有点懵逼，没有找到解决方案 =_= 