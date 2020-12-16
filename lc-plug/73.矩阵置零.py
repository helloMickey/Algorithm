#
# @lc app=leetcode.cn id=73 lang=python3
#
# [73] 矩阵置零
#
from typing import *
# @lc code=start
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        m = len(matrix)
        if m < 1:
            return
        n = len(matrix[0])

        fisrt_col = False
        for i in range(m):
            if matrix[i][0] == 0:
                # 首列应该为 0
                fisrt_col = True
            for j in range(1, n):  # !!!
                if matrix[i][j] == 0:
                    # 对应列头和行尾置 0
                    matrix[0][j] = 0
                    matrix[i][0] = 0

        for i in range(1, m):
            for j in range(1, n):
                if matrix[0][j] == 0 or matrix[i][0] == 0:
                    matrix[i][j] = 0
        
        # 处理行列
        if matrix[0][0] == 0:  # matrix[0][0] 表示行
            for j in range(n):
                matrix[0][j] = 0
        if fisrt_col:
            for i in range(m):
                matrix[i][0] = 0
        
# @lc code=end

if __name__ == "__main__":
    s = Solution()
    s.setZeroes([[1,2,3,4],[5,0,7,8],[0,10,11,12],[13,14,15,0]])