#
# @lc app=leetcode.cn id=62 lang=python3
#
# [62] 不同路径
#

# @lc code=start
class Solution:

    def DFS(self, x, y):
        if x == self.end_x and y == self.end_y:
            return 1
        if x > self.end_x or y > self.end_y:
            return 0
        n1 = self.DFS(x+1, y)  # 向下
        n2 = self.DFS(x, y+1)  # 向右
        return n1 + n2

    def uniquePaths_old(self, m: int, n: int) -> int:
        """
        有很多重复遍历的位置，会超时=》 剪纸；动态规划；
        """
        if m < 1 or n < 1:
            return 0

        self.end_x = m-1
        self.end_y = n-1
        return self.DFS(0, 0)

    def uniquePaths(self, m, n):
        """
        动态规划
        """
        res = [[0 for j in range(n)] for i in range(m)]
        res[-1][-1] = 0
        for i in range(n):
            res[m-1][i] = 1
        for i in range(m):
            res[i][n-1] = 1

        for i in range(m-2, -1, -1):
            for j in range(n-2, -1, -1):
                res[i][j] = res[i+1][j] + res[i][j+1] 

        return res[0][0]
# @lc code=end
if __name__ == "__main__":
    s = Solution()
    s.uniquePaths(3,7)
