#
# @lc app=leetcode.cn id=56 lang=python3
#
# [56] 合并区间
#
from typing import *
# @lc code=start
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) == 0:
            return []
        # 先进行一个排序 n*log(n)
        intervals = sorted(intervals, key = lambda a1:a1[0])
        # 归并 log(n)
        r = [intervals[0]]
        for i in range(len(intervals)):
            # 能合并的都合并
            if intervals[i][0] <= r[-1][1]:
                r[-1][1] = max(r[-1][1], intervals[i][1])  # 区间合并
            else:
                r.append(intervals[i])  # 新增区间
        return r
# @lc code=end
if __name__ == "__main__":
    s = Solution()
    s.merge([[1,4],[0,4]])
