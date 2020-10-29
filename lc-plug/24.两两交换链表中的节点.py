#
# @lc app=leetcode.cn id=24 lang=python3
#
# [24] 两两交换链表中的节点
#

# @lc code=start
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return head  # 包含0/1个元素
        # 先交换前两个使得 prev 不为 None
        temp = head.next
        prev = head
        prev.next = temp.next
        head = temp
        head.next = prev

        # prev -> cur -> cur_n
        while prev.next is not None:
            cur = prev.next
            cur_n = cur.next
            if cur_n == None: # prev -> cur 就结束了
                break
            # 重组 prev -> cur_n -> cur
            prev.next = cur_n
            temp = cur_n.next
            cur_n.next = cur
            cur.next = temp
            # 更新 prev, cur
            prev = cur
        return head
# @lc code=end

# if __name__ == "__main__":
#     s = Solution()
#     head = ListNode(1)
#     head.next = ListNode(2)
#     head.next.next = ListNode(3)
#     head.next.next.next = ListNode(4)
#     s.swapPairs(head)
#     pass