#
# @lc app=leetcode.cn id=31 lang=python3
#
# [31] 下一个排列
#

# @lc code=start
from typing import *
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        l = len(nums)
        i = l-1
        while i > 0:
        # for i in range(l-1, 0, -1): # 10, 9, 8,,,, 1
            idx = i
            if nums[idx] > nums[idx-1]:   
                # idx - 1 处的值需要被替换为一个比他大的数
                j = l-1
                while  j > idx:  # 从小到大找出大于 nums[idx-1] 的值
                    if nums[j] > nums [idx-1]:
                        break
                    j -= 1
                # idx之后的数据中没找到，那就交换 idx 和 idx-1两处的值， j = idx
                # 交换 j 处与 idx-1 处的值
                temp = nums[j]
                nums[j] = nums[idx-1]
                nums[idx-1] = temp

                # reverse
                head, rear = idx, l-1
                break
            i -= 1
        pass
        if i == 0:
            head, rear = 0, l-1   # 全部 reverse
        while head < rear:
            temp = nums[head]
            nums[head] = nums[rear]
            nums[rear] = temp
            head += 1
            rear -= 1
# @lc code=end

if __name__ == "__main__":
    s = Solution()
    s.nextPermutation([1,1,5])