#
# @lc app=leetcode id=3 lang=python
#
# [3] Longest Substring Without Repeating Characters
#

# @lc code=start
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        # 存放所有字符不重复的字串，最后输出时计算最长的
        subs = []
        sub = ""
        for c in s.strip():
            index = sub.find(c)
            if index == -1:
                sub += c
            elif c == " ":
                sub = sub[index+1:]
            else:
                subs.append(sub)
                sub = sub[index+1:] + c

        result = ""
        for item in subs:
            if len(item) > len(result):
                result = item

        return len(result)

        
# @lc code=end


if __name__ == "__main__":
    # s = "pwwkew"
    # s = " "
    s = "    "
    solution = Solution()
    result = solution.lengthOfLongestSubstring(s)
    print(result)