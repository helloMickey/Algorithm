#
# @lc app=leetcode.cn id=101 lang=python3
#
# [101] 对称二叉树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def preorder(self, root):
        if root == None:
            return []
        order = []
        left_trv = self.preorder(root.left)
        right_trv = self.preorder(root.right)
        if left_trv == [] and right_trv != []:
            order.append(-1)
            order.append(root.val)
            order.extend(right_trv)
        elif left_trv != [] and right_trv == []:
            order.extend(left_trv)
            order.append(root.val)
            order.append(-1)
        elif left_trv != [] and right_trv != []:
            order.extend(left_trv)
            order.append(root.val)
            order.extend(right_trv)
        else:
            order.append(root.val)
        print(order)
        return order

    def isSymmetric(self, root: TreeNode) -> bool:
        # 先序遍历 =》对称 ； 左子树先序 == 右子树 后续 ； 这两个思路有问题！！！
        # 先序或者后续对应的树形是多种的！！！

        # 层次序遍历 呢？ =》 可行！！！

        order = self.preorder(root)

        head = 0
        rear = len(order)-1
        while head < rear:
            if order[head] == order[rear]:
                head += 1
                rear -= 1
            else:
                return False
        return True        
        
# @lc code=end

