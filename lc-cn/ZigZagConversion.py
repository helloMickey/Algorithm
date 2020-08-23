"""
https://leetcode-cn.com/problems/zigzag-conversion/
"""

class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        array = list('' for i in range(numRows))
        r_count = 0
        conver = True
        for c in s:
            array[r_count] += c
            conver = not conver if r_count == (numRows-1) or r_count == 0 else conver
            r_count += 1 if not conver else -1
        result = ''.join(array)
        return result

if __name__ == "__main__":
    s = Solution()
    s.convert("PAYPALISHIRING", 3)