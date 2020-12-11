#
# @lc app=leetcode.cn id=107 lang=python3
#
# [107] 二叉树的层次遍历 II
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        if root == None:
            return []
        queue = list()
        result = [[root.val]]
        queue.append(root.left)
        queue.append(root.right)
        layer_c = 2
        while len(queue) > 0:
            c = 0
            layer_nums = []
            temp_c = 0
            while c < layer_c:
                if queue[0] != None:
                    layer_nums.append(queue[0].val)
                    queue.append(queue[0].left)
                    queue.append(queue[0].right)
                    temp_c += 2
                del(queue[0])
                c += 1
            layer_c = temp_c
            if temp_c == 0:
                continue
            result.insert(0, layer_nums)
            # print(result)
        return result
            
# @lc code=end

