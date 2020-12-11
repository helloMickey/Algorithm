#
# @lc app=leetcode.cn id=53 lang=python3
#
# [53] 最大子序和
#

# @lc code=start
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        sum_i = 0
        cur_max = nums[0]
        i = 0
        while i < len(nums):
            n = nums[i]
            sum_i += n
            if  sum_i > cur_max:
                cur_max = sum_i
            
            if sum_i < 0:
                if n > 0:
                    sum_i = n
                else:
                    sum_i = 0    
            i += 1
        return cur_max
# @lc code=end

