#
# @lc app=leetcode.cn id=48 lang=python3
#
# [48] 旋转图像
#

# @lc code=start
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        # 转置
        n = len(matrix)
        for i in range(n):
            for j in range(i, n):
                temp = matrix[i][j]
                matrix[i][j] = matrix[j][i]
                matrix[j][i] = temp

        # 列互换
        mid = int(n/2)
        for j in range(n):
            for i in range(mid):
                temp = matrix[j][i]
                matrix[j][i] = matrix[j][n-1-i]
                matrix[j][n-1-i] = temp
                

# @lc code=end

