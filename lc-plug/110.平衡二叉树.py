#
# @lc app=leetcode.cn id=110 lang=python3
#
# [110] 平衡二叉树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def depth(self, root):
        if root == None:
            return 0
        else:
            l_d = self.depth(root.left)
            r_d = self.depth(root.right)
            if abs(l_d - r_d) > 1:
                self.flag = False  # 某一个节点不满足时
            return max(l_d, r_d) + 1
    def isBalanced(self, root: TreeNode) -> bool:
        self.flag = True
        self.depth(root)
        return self.flag
        
# @lc code=end

