#
# @lc app=leetcode.cn id=27 lang=python3
#
# [27] 移除元素
#

# @lc code=start
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        size = len(nums)
        rear = size-1
        cur = 0
        while cur <= rear:
            if nums[cur] == val:
                nums[cur] = nums[rear]
                rear -= 1
            else:
                cur += 1
            pass
        return cur
# @lc code=end

