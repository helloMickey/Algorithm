#
# @lc app=leetcode.cn id=118 lang=python3
#
# [118] 杨辉三角
#

# @lc code=start
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = []
        if numRows < 1:
            return res
        res.append([1])
        for i in range(1, numRows):
            cur = [1]
            for j in range(i-1):
                cur.append(res[i-1][j] + res[i-1][j+1])
            cur.append(1)
            
            res.append(cur)
            
        return res
# @lc code=end

