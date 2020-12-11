#
# @lc app=leetcode.cn id=33 lang=python3
#
# [33] 搜索旋转排序数组
#
from typing import *


# @lc code=start
class Solution:
    def binary_search(self, nums, target):
        head = 0
        rear = len(nums)-1
        while head <= rear:
            mid = (head + rear) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                head = mid + 1
            else:
                rear = mid - 1
        return -1  # 没找到

    def search(self, nums: List[int], target: int) -> int:
        if nums == []:
            return -1
        if len(nums) == 1:
            if nums[0] == target:
                return 0
            else:
                return -1
        head = 0
        rear = len(nums) - 1
        mid = (head + rear) // 2
        if nums[mid] == target:
            return mid
        if nums[head] == target:
            return head
        if nums[rear] == target:
            return rear

        if nums[head] < nums[mid]:  # 前半部有序
            if nums[head] < target and target < nums[mid]:  # 只可能在前半部中
                s_r = self.binary_search(nums[:mid], target)
                if s_r != -1:
                    return head + s_r
                else:
                    return -1
            else:  # 一定不再前半部中, 可能在后半部中
                s_r = self.search(nums[mid+1:], target)
                if s_r != -1:
                    return mid+1 + s_r  # 在后半部
                else:
                    return -1
        else:  # 后半部有序
            if nums[mid] < target and target < nums[rear]:  # 只可能在后半部中
                s_r = self.binary_search(nums[mid+1:], target)
                if s_r != -1:
                    return mid+1 + s_r
                else:
                    return -1
            else:  # 一定不在后半部，可能在前半部
                s_r = self.search(nums[:mid], target)
                if s_r != -1:
                    return head + s_r  # 在前半部
                else:
                    return -1
# @lc code=end
if __name__ == "__main__":
    s = Solution()
    a = s.search([4,5,6,7,0,1,2], 6)
    print(a)
    pass