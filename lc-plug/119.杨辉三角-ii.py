#
# @lc app=leetcode.cn id=119 lang=python3
#
# [119] 杨辉三角 II
#

# @lc code=start
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        if rowIndex == 0:
            return [1]
        if rowIndex == 1:
            return [1,1]
        # 使用一个对列来保存数据
        res = [1, 1]
        for i in range(2, rowIndex+1):
            prv = res[0]
            for j in range(1, len(res)):
                js = res[j] + prv
                prv = res[j]
                res[j] = js
            res.append(1)
        return res
# @lc code=end