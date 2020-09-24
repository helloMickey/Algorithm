"""
https://leetcode-cn.com/problems/3sum/
"""
from typing import *
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        # r=set()
        r=[]
        nums.sort()
        i = 0
        while i < (len(nums)-2):
            two_sum = 0-nums[i]
            j_1 = i + 1
            j_2 = len(nums) -1
            # 找两数之和, 这边可以改进为折中法查找，会提升速度
            while j_1 < j_2:
                if (nums[j_1] + nums[j_2]) == two_sum:
                    r.append([nums[i], nums[j_1], nums[j_2]])
                    temp = nums[j_1]
                    while (temp == nums[j_1]) and (j_1 < j_2):  # 左指针右移
                        j_1 += 1
                elif (nums[j_1] + nums[j_2]) < two_sum:
                    j_1 += 1 # 左指针右移
                else:
                    j_2 -= 1 # 右指针左移
            # 为了保证结果中没有出现重复的
            temp = nums[i]
            while (temp == nums[i]) and (i < len(nums)-2):  # 重复元素跳过
                i += 1
            pass
        return r

if __name__ == "__main__":
    s = Solution()
    s.threeSum([0,0,0])
