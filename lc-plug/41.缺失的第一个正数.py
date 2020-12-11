#
# @lc app=leetcode.cn id=41 lang=python3
#
# [41] 缺失的第一个正数
#
from typing import *
# @lc code=start
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        if nums == []:
            return 1
        N = len(nums)
        for i in range(N):
            # nums[nums[i] - 1] != nums[i] 该元素处在正确的位置上！
            while 0<nums[i] and nums[i]<=N and nums[nums[i] - 1] != nums[i]:
                # 交换位置
                temp = nums[nums[i] - 1]
                nums[nums[i] - 1] = nums[i]
                nums[i] = temp
             
        for i in range(N): # 0不是正整数
            n = nums[i]
            if (i+1) != n:
                return i + 1
        return N+1      
# @lc code=end
if __name__ == "__main__":
    s = Solution()
    a = s.firstMissingPositive([3,4,-1,1])
    print(a)
