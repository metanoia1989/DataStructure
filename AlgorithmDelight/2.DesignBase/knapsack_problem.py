#!/usr/bin/env python3
#-*- coding: utf-8 -*-

"""
0-1背包问题

来看一个具体的例子，有一个背包，最多能承载重量为 C=150的物品，
现在有 7个物品（物品不能分割成任意大小），编号为 1～7，
重量分别是 wi =[35,30,60,50,40,10,25]，
价值分别是 pi =[10,40,30,50,35,40,30]，
现在从这 7 个物品中选择一个或多个装入背包，
要求在物品总重量不超过 C 的前提下，所装入的物品总价值最高。

这个问题的子问题可以按照选择物品装入背包的过程按部就班地一步一步分解，
将子问题定义为在被背包容量还有 C’的情况下，选择一个物品装入背包。
C’的初始值就是 150，假如选择了一个重为 35的物品，
则子问题就变成在背包容量 C’ 是 115的情况下，
从剩下的 6件物品中选择一个物品，
这样每选择一个物品就相当于子问题的规模减小了。

**使用贪婪策略进行求解**        
常见的贪婪策略有三种。
第一种策略是根据物品价值选择，每次都选价值最高的物品。
根据这个策略最终选择装入背包的物 品编号依次是 4、2、6、5，
此时包中物品总重量是 130，总价值是 165。

第二种策略是根据物品重量选择，每次都选择重量最轻的物品。
根据这个策略最终选择装入背包的物品编号依次是 6、 7、2、1、5，
此时包中物品总重量是 140，总价值是 155。 

第三种策略是定义一个价值密度的概念，每次选择都选价值密度最高的物品。
物品的价值密度 s i 定义为 p i /w i ，这 7件物品的价值密度分别为
si =[0.286,1.333,0.5,1.0,0.875,4.0,1.2]。
根据这个策略最终选择装入背包的物品编号依次是 6、2、7、4、1，
此时包中物品的总重量是 150，总价值是 170。

**算法实现**        
首先定义背包问题的数据结构，根据问题描述，可以直接知道每个物品有两个属性，分别是重量和价值。
此外，每个物品只能被选择一次，因此还需要给每个物品增加一个选择状态的属性。
"""

from typing import List, Callable
from copy import deepcopy

class TagObject():
    """
    物品对象
    """

    def __init__(self, weight: int, price: int) -> None:
        """
        0 未选中   1 已选中   2 已经不可选
        2 表示用当前策略选择的物品导致总重量超过背包承重量，在这种情况下，如果放弃这个物品，
        按照策略从剩下的物品中再选一个，有可能就能满足背包承重的要求。因此，设置了一个状态 2，
        表示当前选择物品不合适，下次选择也不要再选这个物品。
        """
        self.status = 0 
        self.weight = weight
        self.price = price

        
class TagKnapsack():
    """
    背包问题包括两个属性，一个是可选物品列表，一个是背包总的承重量。
    """
    def __init__(self, objs: List[TagObject], totalC: int):
        self.objs: List[TagObject] = objs # 可选物品列表
        self.totalC: int = totalC # 背包的总称重量
        
def ChooseFunc1(objs: List[TagObject], c: int):
    """
    第一种策略是根据物品价值选择，每次都选价值最高的物品。
    """
    index: int = -1
    mp: int = 0 # 当前背包中物品的最高价值
    for i in range(len(objs)):
        if objs[i].status == 0 and objs[i].price > mp:
            mp = objs[i].price
            index = i

    return index

def ChooseFunc2(objs: List[TagObject], c: int):
    """
    第二种策略是根据物品重量选择，每次都选择重量最轻的物品。
    """
    index: int = -1
    mw: int = 10000
    for i in range(len(objs)):
        if objs[i].status == 0 and objs[i].weight < mw:
            mw = objs[i].weight
            index = i

    return index

def ChooseFunc3(objs: List[TagObject], c: int):
    """
    第三种策略是定义一个价值密度的概念，每次选择都选价值密度最高的物品。
    price density
    """
    index: int = -1
    ms: float = 0.0
    for i in range(len(objs)):
        curr_si: float = objs[i].price / objs[i].weight
        if objs[i].status == 0 and curr_si > ms:
            ms = curr_si
            index = i

    return index

def GreedyAlgo(problem: TagKnapsack, spFunc: Callable):
    """
    贪婪算法策略
    """
    idx: int = -1
    ntc: int = 0
    
    # spFunc 每次选最符合策略的那个物品，选后再检查
    idx = spFunc(problem.objs, problem.totalC - ntc)
    while idx != -1:
        # 所选物品是否满足背包承重要求
        if (ntc + problem.objs[idx].weight) <= problem.totalC:
            problem.objs[idx].status = 1
            ntc += problem.objs[idx].weight
        else:
            # 不能选这个物品了，做个标记后重新选
            problem.objs[idx].status = 2
        
        idx = spFunc(problem.objs, problem.totalC - ntc)

    PrintResult(problem.objs)
    

def PrintResult(objs: List[TagObject]):
    totalW: int = 0
    totalP: int = 0
    
    for i in range(len(objs)):
        if objs[i].status == 1:
            totalW += objs[i].weight
            totalP += objs[i].price
            print("object {index}: weight={weight}, price={price}"
                .format(index=i+1, weight=objs[i].weight, price=objs[i].price))
                
    print("total weight : {}, total price: {}\n".format(totalW, totalP))
    
if __name__ == "__main__":
    objs = [
        TagObject(35, 10),
        TagObject(30, 40),
        TagObject(60, 30),
        TagObject(50, 50),
        TagObject(40, 35),
        TagObject(10, 40),
        TagObject(25, 30),
    ]
    totalC = 150
    problem = TagKnapsack(objs=objs, totalC=totalC)
    GreedyAlgo(deepcopy(problem), ChooseFunc1)
    GreedyAlgo(deepcopy(problem), ChooseFunc2)
    GreedyAlgo(deepcopy(problem), ChooseFunc3)