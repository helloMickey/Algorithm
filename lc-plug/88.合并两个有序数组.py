#
# @lc app=leetcode.cn id=88 lang=python3
#
# [88] 合并两个有序数组
#

# @lc code=start
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        rear = m+n-1
        p_1 = m - 1
        p_2 = n - 1
        while rear >= 0:
            if p_1 < 0 or p_2 < 0:
                break
            if nums1[p_1] > nums2[p_2]:
                nums1[rear] = nums1[p_1]
                p_1 -= 1
            else:
                nums1[rear] = nums2[p_2] 
                p_2 -=1
            rear -= 1
        while p_1 >=0 and rear>=0:
            nums1[rear] = nums1[p_1]
            rear -= 1
            p_1 -= 1

        while p_2 >=0 and rear>=0:
            nums1[rear] = nums2[p_2]
            rear -= 1
            p_2 -= 1

# @lc code=end

