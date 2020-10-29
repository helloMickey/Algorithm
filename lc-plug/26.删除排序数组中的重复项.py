#
# @lc app=leetcode.cn id=26 lang=python3
#
# [26] 删除排序数组中的重复项
#

# @lc code=start
from typing import *

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        counter = 0
        for i in range(1, len(nums)):
            if nums[i] > nums[counter]:
                counter += 1
                nums[counter] = nums[i]
            pass
        return counter + 1
# @lc code=end

