"""
https://leetcode-cn.com/problems/reverse-integer/
"""
class Solution:
    def reverse(self, x: int) -> int:
        s = str(x)
        if s[0] == '-':
            s_n = '-' + s[1:][::-1]
        else:
            s_n = s[::-1]
        result = int(s_n)
        return result if -2 ** 31 <= result <= 2 ** 31 - 1 else 0

if __name__ == "__main__":
    s = Solution()
    s.reverse("-123")