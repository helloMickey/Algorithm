#
# @lc app=leetcode.cn id=64 lang=python3
#
# [64] 最小路径和
#

# @lc code=start
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m = len(grid)
        if m < 1:
            return 0
        n = len(grid[0])

        for i in range(n-2, -1, -1):  
            grid[m-1][i] += grid[m-1][i+1] # 只能向右走

        for i in range(m-2, -1, -1):  
            grid[i][n-1] += grid[i+1][n-1] # 只能向下走    

        for i in range(m-2, -1, -1):
            for j in range(n-2, -1, -1):
                grid[i][j] += min(grid[i+1][j], grid[i][j+1])  # 选出向下和向右中小的
                
        return grid[0][0]
# @lc code=end

