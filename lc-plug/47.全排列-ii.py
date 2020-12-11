#
# @lc app=leetcode.cn id=47 lang=python3
#
# [47] 全排列 II
#

# @lc code=start
class Solution:
    def dfs(self, remain):
        if remain == []:
            return []
        rt = []
        ban = []
        for i, num in enumerate(remain):
            if num in ban:
                continue
            ban.append(num) # 遍历过的就不要了
            sub = remain.copy()
            del(sub[i])  # 跳过 i
            cur_rt = self.dfs(sub)
            if cur_rt == []:
                rt.append([num])
                continue
            for item in cur_rt:
                item.append(num)
                rt.append(item)
        return rt
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        return self.dfs(nums)
# @lc code=end

