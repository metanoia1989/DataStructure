#!/usr/bin/env python3
#-*- coding: utf-8 -*-


from typing import List

"""
倒水问题
有三个容积分别是 3升、5升和 8升的水桶，其中容积为 8升的水桶中装满了水， 
容积为 3升和容积为 5升的水桶是空的。三个水桶都没有体积刻度，现在需要将大
水桶中的 8升水等分成两份，每份都是 4升水，附加条件是只能使用另外两个空水桶，
不能借助其他辅助容器。
"""

BUCKETS_COUNT = 3
bucket_capicity: List[int] = [ 8, 5, 3 ] # 桶的容量
bucket_init_state: List[int] = [ 8, 0, 0 ] # 桶的初始状态
bucket_final_state: List[int] = [ 4, 4, 0 ] # 桶的最终状态

class Action:
    """
    倒水动作的数据结构
    from 从哪个水桶中倒水
    to 将水倒向哪个桶
    water 倒水动作所倒的水量
    """
    def __init__(self, from: int, to: int, water: int) -> None:
        self.from: int = from
        self.to: int = to
        self.water: int = water
        
class BucketState:
    """
    存水状态
    """
    def __init__(self) -> None:
        self.bucket_s: List[int] = None
        self.curAction: Action = None
        
    def IsBucketEmpty(self, bucket: int) -> bool:
        """
        桶是否是空的    
        """
        assert(bucket >= 0 and bucket <BUCKETS_COUNT)
        return self.bucket_s[bucket] == 0

    def IsBucketFull(self, bucket: int) -> bool:
        """
        桶是否是满的
        """
        assert(bucket >= 0 and bucket <BUCKETS_COUNT)
        return self.bucket_s[bucket] >= bucket_capicity[bucket]
        
    def CanTakeDumpAction(self, from: int, to: int) -> bool:
        """
        能否进行倒水动作
        """
        assert(from >= 0 and from <BUCKETS_COUNT)
        assert(to >= 0 and to < BUCKETS_COUNT)
        # 不是同一个桶，且from桶中有水，且to桶中不满    
        if from != to and not self.IsBucketEmpty(from) \
            and not self.IsBucketFull(to):
            return True
        
        return False
    
    

        
def SearchState(states: List[BucketState]):
    """
    状态搜索
    """
    current: BucketState  = states[-1] # 每次都从当前状态开始
    # if current
