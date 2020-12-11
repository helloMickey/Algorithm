#
# @lc app=leetcode.cn id=100 lang=python3
#
# [100] 相同的树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if None in [p, q]:
            return p == q
            
        # 前序遍历相同
        if p.val != q.val:
            return False
        elif self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right):
            return True
        else:
            return False
        pass
# @lc code=end

