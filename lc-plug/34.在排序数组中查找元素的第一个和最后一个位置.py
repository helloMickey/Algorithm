#
# @lc app=leetcode.cn id=34 lang=python3
#
# [34] 在排序数组中查找元素的第一个和最后一个位置
#

# 思路二：
# 利用二分思想先找其左边界，再找其右边界即可，
# 注意找左边界的时候，由右侧逼近；找右边界的时候，由左侧逼近，即可。

# @lc code=start
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        # 首先二分查找，没找到返回 [-1, -1]; 找到后向两边延伸
        head = 0
        rear = len(nums) - 1
        find = False
        while head <= rear:
            mid = int((head + rear) / 2)
            if nums[mid] == target:
                find = True
                break
            elif nums[mid] < target:
                head = mid + 1
            else:
                rear = mid - 1
        if find:
            low_bound, up_bound = mid, mid
            while low_bound > 0 and  nums[low_bound - 1] == target:
                low_bound -= 1
            while up_bound < len(nums) - 1 and nums[up_bound + 1] == target:
                up_bound += 1
            return [low_bound, up_bound]
        else:
            return [-1, -1]
        
# @lc code=end

