"""
https://leetcode-cn.com/problems/string-to-integer-atoi/
"""
import re
class Solution:
    def myAtoi(self, s: str) -> int:
        # -*[0-9]*
        p = '^\s*[+-]{0,1}\d+'
        a = re.search(p, s)
        if a is None:
            return 0
        s = s[a.span()[0] : a.span()[1]]
        num = int(s.strip())
        if num > 2**31 - 1:
            return 2**31 - 1
        elif num < -2**31:
            return -2**31
        else:
            return num
        
        