#
# @lc app=leetcode.cn id=39 lang=python3
#
# [39] 组合总和
#

# @lc code=start
from typing import *
class Solution:
    def dfs(self, candidates, target):
        res = []
        for idx, c in enumerate(candidates):

            if (target - c) == 0:
                res.append([c])
            elif (target - c) > 0 :
                cur_res = self.dfs(candidates[idx:], target - c)
                if cur_res == []:
                    continue
                for i in range(len(cur_res)):
                    cur_res[i].append(c)  # 在回溯路径上加上 c
                    res.append(cur_res[i])
            else:
                break  # 后面的不用遍历了
        return res
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        # 进行 sort
        candidates = sorted(candidates)
        res = self.dfs(candidates, target)
        return res
        
# @lc code=end
if __name__ == "__main__":
    s = Solution()
    s.combinationSum([2,7,6,3,5,1], 9)

