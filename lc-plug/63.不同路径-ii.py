#
# @lc app=leetcode.cn id=63 lang=python3
#
# [63] 不同路径 II
#
from typing import *
# @lc code=start
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        """
        obstacleGrid[i][j] 为 1表示障碍
        为 -n 表示从此处至结尾有 n 条路
        """
        m = len(obstacleGrid)
        if m < 1:
            return 0
        n = len(obstacleGrid[0])
        if obstacleGrid[m-1][n-1] == 1 or obstacleGrid[0][0] == 1:
            return 0
        obstacleGrid[m-1][n-1] = -1  # 重要
        for i in range(-2, -n-1, -1):
            if obstacleGrid[-1][i] == 1:
                continue  # 自身是障碍
            # 前方有无障碍
            obstacleGrid[-1][i] = obstacleGrid[-1][i+1] if (obstacleGrid[-1][i+1] != 1) else 0
        for i in range(-2, -m-1, -1):
            if obstacleGrid[i][-1] == 1:
                continue  # 自身是障碍
            obstacleGrid[i][-1] = obstacleGrid[i+1][-1] if (obstacleGrid[i+1][-1] != 1) else 0
        
        for i in range(-2, -m-1, -1):
            for j in range(-2, -n-1, -1):
                if obstacleGrid[i][j] == 1:
                    continue  # 自身就是障碍
                if obstacleGrid[i+1][j] == 1 and obstacleGrid[i][j+1]==1: 
                    obstacleGrid[i][j] = 0  # 下方和右方都是障碍
                elif obstacleGrid[i+1][j] != 1 and obstacleGrid[i][j+1] != 1:
                    obstacleGrid[i][j] = obstacleGrid[i+1][j] + obstacleGrid[i][j+1]
                elif obstacleGrid[i+1][j] != 1:
                    obstacleGrid[i][j] = obstacleGrid[i+1][j]
                else:
                    obstacleGrid[i][j] = obstacleGrid[i][j+1]

        return - obstacleGrid[0][0]
# @lc code=end
if __name__ == "__main__":
    s=Solution()
    s.uniquePathsWithObstacles([[0,1],[0,0]])

