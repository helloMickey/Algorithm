#
# @lc app=leetcode.cn id=66 lang=python3
#
# [66] 加一
#
from typing import *
# @lc code=start
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        # 进位
        rear = len(digits) - 1
        digits[rear] += 1
        while digits[rear] > 9:
            digits[rear] = digits[rear]%10  # 保留各位，进一
            rear -= 1
            if rear < 0:
                break
            digits[rear] += 1    
        if rear < 0:
            digits.insert(0, 1)  # 头部进 1
        return digits
# @lc code=end

