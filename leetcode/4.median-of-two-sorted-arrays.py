#
# @lc app=leetcode id=4 lang=python
#
# [4] Median of Two Sorted Arrays
#

# @lc code=start
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        
# @lc code=end


if __name__ == "__main__":
    nums1 = [1, 3]
    nums2 = [2]
    solution = Solution()
    result = solution.findMedianSortedArrays(nums1, nums2)
    print(result)