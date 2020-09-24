"""
https://leetcode-cn.com/problems/3sum-closest/
"""
from typing import *
class Solution:
    def threeSumClosest(self, nums: List[int], target:int) -> int:
        nums.sort()  # 从小到大排序
        size = len(nums)
        i = 0
        min_dis = abs(target - sum([nums[0], nums[1], nums[2]]))
        closest_sum = sum([nums[0], nums[1], nums[2]])
        while i < (size - 2):
            p_1 = i + 1
            p_2 = size - 1
            while p_1 < p_2:
                cur_sum = sum([nums[i], nums[p_1], nums[p_2]])
                if cur_sum == target:
                    closest_sum = target
                    i = size-2  # 跳出两个循环
                    break
                elif cur_sum < target:
                    p_1 += 1
                else:
                    p_2 -= 1

                if abs(target - cur_sum) < min_dis:
                    min_dis = abs(target - cur_sum)
                    closest_sum = cur_sum  # 更新最接近的和
            i += 1
            pass
        return closest_sum

if __name__ == "__main__":
    s = Solution()
    s.threeSumClosest([0,2,1,-3], 1)