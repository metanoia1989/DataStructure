#
# @lc app=leetcode id=448 lang=python3
#
# [448] Find All Numbers Disappeared in an Array
#

import random
from typing import List

# @lc code=start
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        if nums is None:
            nums = [4,3,2,7,8,2,3,1] 
        
        # 排序数组，大于n的值设置为0，然后相应的值放置到相应的索引上
        # 重复的覆盖，最后迭代数组，值为0的就是没有的值
        i = 0
        size = len(nums)
        while i < size:
            value = nums[i]
            # 剔除不在 1-n之间的值 
            if value > size or value < 1:
                nums[i] = 0
            # 将值放在对应的位置上，如果要交换的值相等，设为0
            elif value != nums[value-1]:
                print("i, nums[i], nums[value]", i, nums[i], nums[value-1], str(nums))
                nums[i] = nums[value-1]
                nums[value-1] = value
            elif i == value - 1 and i == nums[value-1]-1:
                pass
            else:
                nums[i] = 0
            i += 1
        
        i = 0
        result = []
        while i < size:
            if nums[i] == 0:
                result.append(i) 
            i += 1

        print(str(result))
        return result



# @lc code=end


def extra_space_solve():
    """
    这里要求不能使用额外的空间来实现 O(n) 的解决方法，
    使用额外的空间的话，创建 0 ~ n 的数组，迭代 nums 依次检测索引是否存在
    存在则略过，不存在则是要求的值
    """
    nums = [4,3,2,7,8,2,3,1] 
    n = random.randint(1, len(nums))
    check_map = { key: 0 for key in range(0, n)} 
    result_arr = []
    for i in nums:
        if i > n:
            continue
        if check_map.get(i-1) is not None:
            check_map[i-1] += 1
        
    result_arr = [ x[0] + 1 for x in filter(lambda item: item[1] == 0, check_map.items()) ] 

    print(n, "---->", str(result_arr))
    

if __name__ == "__main__":
    # extra_space_solve()
    
    # nums = [1, 1]
    # solution = Solution()
    # solution.findDisappearedNumbers(nums)