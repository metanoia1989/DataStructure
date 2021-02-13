#
# @lc app=leetcode id=2 lang=python
#
# [2] Add Two Numbers
#

# @lc code=start
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        result = ListNode()
        curr = result
        carry = 0 # 进位
        while l1 is not None or l2 is not None:
            if l1 is not None and l2 is not None:
                curr.val = curr.val + l1.val + l2.val
                carry = curr.val // 10
                curr.val = curr.val % 10
                l1 = l1.next
                l2 = l2.next
                curr.next = ListNode(carry)
                curr = curr.next
            elif l1 is not None:
                curr.val = curr.val + l1.val 
                carry = curr.val // 10
                curr.val = curr.val % 10
                l1 = l1.next
                curr.next = ListNode(carry)
                curr = curr.next
            elif l2 is not None:
                curr.val = curr.val + l2.val 
                carry = curr.val // 10
                curr.val = curr.val % 10
                l2 = l2.next
                curr.next = ListNode(carry)
                curr = curr.next
            elif carry != 0:
                curr.next = ListNode(carry)
                curr = curr.next
            
            # 到了最后一个，如果 l1 和 l2 都到了终点，并且curr值为0，则退一格
            if l1 is None and l2 is None and curr.val == 0:
                temp = result
                while temp is not None:
                    if temp.next == curr:
                        temp.next = None
                        break 
                    temp = temp.next
                
        return result
            
                

        
# @lc code=end

def print_list_node(listNode):
    result = []
    while listNode is not None:
        result.append(listNode.val)
        listNode = listNode.next
    print(str(result))

if __name__ == "__main__":
    l1 = ListNode(2)
    l1.next = ListNode(4)
    l1.next.next = ListNode(3)

    l2 = ListNode(5)
    l2.next = ListNode(6)
    l2.next.next = ListNode(4)

    solution = Solution()
    result = solution.addTwoNumbers(l1, l2)
    print_list_node(result)