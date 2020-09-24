"""
https://leetcode-cn.com/problems/longest-common-prefix/
"""
from typing import *
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0 or ('' in strs):
            return "" 
        strs = sorted(strs, key=lambda s: len(s))  # 按照字符串长度进行比较
        i = 0
        size = len(strs[0])
        while i < size:
            c = strs[0][i]
            comp = [c == s[i] for s in strs]
            if sum(comp) != len(strs):
                # 说明有字符串不匹配该c
                break
            i+=1
        return strs[0][:i]

if __name__ == "__main__":
    s = Solution()
    s.longestCommonPrefix(["aa", "a"])
    