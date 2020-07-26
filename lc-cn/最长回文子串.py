"""
https://leetcode-cn.com/problems/longest-palindromic-substring/

dp[i][j] 表示 s[i]到s[j]之间的字符串为回文串

if i > j:
    continue
if s[i] !=s[j]:
    dp[i][j] = False
elif dp[i+1][j-1] == True:
    dp[i][j] = True 
"""
import numpy as np
class Solution:
    def longestPalindrome(self, s:str)->str:
        if len(s) <= 1:
            return s
        size = len(s)
        result = s[0]
        dp = np.zeros((size, size))
        for i in range(size):
            dp[i][i] = True
        for l in range(1, size):
            for i in range(0, size-l):
                j = i+l
                if s[i] != s[j]:
                    dp[i][j] = False
                elif (i+1) < j :
                    if dp[i+1][j-1] == True:
                        dp[i][j] = True
                        if (j - i + 1) > len(result):
                            result = s[i:j+1]
                else:
                   dp[i][j] = True 
                   if (j - i + 1) > len(result):
                        result = s[i:j+1] 
                pass
        return result

if __name__ == "__main__":
    s = Solution()
    print(s.longestPalindrome("abcda"))