"""
利用中序和前序重建二叉树
https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/
"""
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
from typing import *

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if (inorder is None) or len(inorder) == 0:
            return None
        if len(inorder) == 1:
            return TreeNode(inorder[0])
        cur_val = preorder[0]
        for i, v in enumerate(inorder):
            if cur_val == v:
                break
        tree_root = TreeNode(cur_val)
        tree_root.left = self.buildTree(preorder[1:1+i], inorder[0:i])
        tree_root.right = self.buildTree(preorder[i+1:], inorder[1+i:])
        return tree_root

if __name__ == "__main__":
    s = Solution()
    s.buildTree(preorder=[3,9,20,15,7], inorder = [9,3,15,20,7])