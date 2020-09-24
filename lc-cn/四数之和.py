"""
https://leetcode-cn.com/problems/4sum/
"""

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        r=[]
        nums.sort()
        i = 0
        while i < (len(nums)-3):
            j = i + 1
            while j < (len(nums)-2):
                two_sum = target - nums[i] - nums[j]
                j_1 = j + 1
                j_2 = len(nums) -1
                while j_1 < j_2:
                    if (nums[j_1] + nums[j_2]) == two_sum:
                        r.append([nums[i], nums[j], nums[j_1], nums[j_2]])
                        temp = nums[j_1]
                        while (temp == nums[j_1]) and (j_1 < j_2):  # 左指针右移
                            j_1 += 1
                    elif (nums[j_1] + nums[j_2]) < two_sum:
                        j_1 += 1 # 左指针右移
                    else:
                        j_2 -= 1 # 右指针左移

                temp = nums[j]
                while (temp == nums[j]) and (j < len(nums)-2):  # 重复元素跳过
                    j += 1
            temp = nums[i]
            while (temp == nums[i]) and (i < len(nums)-3):  # 重复元素跳过
                i += 1
        return r