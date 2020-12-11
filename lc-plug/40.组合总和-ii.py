#
# @lc app=leetcode.cn id=40 lang=python3
#
# [40] 组合总和 II
#
from typing import *
# @lc code=start
class Solution:
    def dfs(self, remain, target):
        res = []
        ban = []
        for i in range(len(remain)):
            num = remain[i]
            if num in ban:
                continue
            ban.append(num)  # 遍历过的 ban 掉
            if (target - num) == 0:
                res.append([num])
                continue
            elif (target - num) < 0:
                continue
            else:
                cur_res = self.dfs(remain[i+1:], target-num)
                for item in cur_res:
                    item.append(num) # 路径上添加 num
                    res.append(item)
        return res
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        if candidates == []:
            return []
        candidates = sorted(candidates)
        return self.dfs(candidates, target)
# @lc code=end

if __name__ == "__main__":
    s = Solution()
    s.combinationSum2([10,1,2,7,6,1,5], 8)