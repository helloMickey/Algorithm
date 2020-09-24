"""
https://leetcode-cn.com/problems/roman-to-integer/
"""
class Solution:
    def romanToInt(self, s: str) -> int:
        vocab = {
            'I':1,
            'V':5,
            'X':10,
            'L':50,
            'C':100,
            'D':500,
            'M':1000,
            'IV':4,
            'IX':9,
            'XL':40,
            'XC':90,
            'CD':400,
            'CM':900
        }
        r = 0
        i = 0
        while i < (len(s)-1):
            if s[i:i+2] in vocab.keys():
                r += vocab[s[i:i+2]]
                i += 1
            else:
                r += vocab[s[i]]
            i += 1
        # 判断后最后一个字符是否已经被计算
        if i != len(s): # 最后一个字符没有包含计算
            r += vocab[s[-1]]
        return r

if __name__ == "__main__":
    s = Solution()
    s.romanToInt('D')