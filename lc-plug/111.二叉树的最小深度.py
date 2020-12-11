#
# @lc app=leetcode.cn id=111 lang=python3
#
# [111] 二叉树的最小深度
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if root == None:
            return 0
        # 层次序遍历
        node_queue = list()
        node_queue.append(root)
        layer = 0
        while len(node_queue) > 0:
            layer += 1
            cur_n = len(node_queue)  # 该层的node数
            # print(cur_n)
            while cur_n > 0:
                node = node_queue[0]
                if node.left==None and node.right==None:
                    return layer
                if node.left != None:
                    node_queue.append(node.left)
                if node.right != None:
                    node_queue.append(node.right)
                del(node_queue[0])
                cur_n -= 1
            # 一层遍历结束
        pass
# @lc code=end

