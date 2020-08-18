"""
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
from collections import defaultdict
from typing import *
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        rec = defaultdict(list)  # 充当 hash table
        for i, num in enumerate(nums):
            rec[num].append(i)
        nums.sort()
        head_p = 0
        rear_p = len(nums) - 1
        while head_p != rear_p:
            a = nums[head_p]
            b = nums[rear_p]
            if (a+b) == target:
                ori_idx_b = rec[b].pop()
                ori_idx_a = rec[a].pop()
                return [ori_idx_a, ori_idx_b]
            elif (a+b) > target:
                rear_p -= 1
            else:
                head_p += 1