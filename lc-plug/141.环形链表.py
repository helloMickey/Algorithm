'''
Author: your name
Date: 2021-01-05 11:39:07
LastEditTime: 2021-01-05 11:43:57
LastEditors: Please set LastEditors
Description: In User Settings Edit
FilePath: \Arteries_01-04-1800c:\chen_project\Algorithm\lc-plug\141.环形链表.py
'''
#
# @lc app=leetcode.cn id=141 lang=python3
#
# [141] 环形链表
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if not head:
            return False
        p0, p1 = head, head.next
        while(p0 != None and p1 != None):
            if p0 == p1:
                return True
            p0 = p0.next
            p1 = p1.next
            if not p1:
                return False
            else:
                p1 = p1.next
        return False
        
# @lc code=end

