#
# @lc app=leetcode.cn id=28 lang=python3
#
# [28] 实现 strStr()
#

# @lc code=start
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle == "":
            return 0
        if len(haystack) < len(needle):
            return -1
        for i in range(0, len(haystack)-len(needle)+1):
            if haystack[i: i+len(needle)] == needle:
                return i
            pass
        return -1
# @lc code=end

