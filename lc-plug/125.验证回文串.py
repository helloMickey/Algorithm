#
# @lc app=leetcode.cn id=125 lang=python3
#
# [125] 验证回文串
#

# @lc code=start
class Solution:
    def isPalindrome(self, s: str) -> bool:
        s_prep = "".join([ch.lower() if ch.isalnum() else "" for ch in s])
        head = 0
        rear = len(s_prep)-1
        while head < rear:
            if s_prep[head] != s_prep[rear]:
                return False
            head += 1
            rear -= 1
        return True
# @lc code=end

