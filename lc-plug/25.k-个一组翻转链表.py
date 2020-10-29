#
# @lc app=leetcode.cn id=25 lang=python3
#
# [25] K 个一组翻转链表
#

# @lc code=start
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def reverse(self, head):
        '''
        反转整个链表
        '''
        cur = head.next
        prev = head
        while cur is not None:
            temp = cur.next
            cur.next = prev
            prev = cur
            cur = temp
            # pass
        head.next = None
        return prev  # rear ->  -> head
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if (k==1) or  (head is None) or (head.next is None):
            return head
        pre_head = ListNode(-1)
        pre_head.next = head
        pre_brk = pre_head
        cur = head
        # 遍历整个链表
        while cur is not None:
            start = cur  # 待转向链的开头
            count = k-1
            while count > 0 and (cur is not None):
                cur = cur.next
                count -= 1

            if cur is None:
                # 剩余的不足 k 各
                pre_brk.next = start  # 本次的不反转了，直接续上
                break
            
            # 
            end = cur
            brk_next = cur.next

            end.next = None  # 断链  start->  -> end
            pre_brk.next = self.reverse(start)  #  end ->   -> start
            
            pre_brk = start  
            cur = brk_next

        return pre_head.next
# @lc code=end

