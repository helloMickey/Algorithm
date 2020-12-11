#
# @lc app=leetcode.cn id=32 lang=python3
#
# [32] 最长有效括号
#

# @lc code=start
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        dp = [0] * (len(s) + 1)
        for i in range(1, len(s)): # 第i个位置的字符，从1开始计数 
            j = i + 1  # 表示dp中的位置
            if s[i] == '(':
                dp[j] = 0
            else:  # ')'
                if s[i-1] == '(':
                    dp[j] = dp[j-2] + 2
                else : # ))
                    if (i-dp[j-1]) > 0 and s[i-dp[j-1] - 1] == '(':  # ( ....))
                        dp[j] = dp[j-1] + 2 + dp[j-dp[j-1]-2]
                    else:
                        dp[j] = 0
        return max(dp)

# @lc code=end
if __name__ == "__main__":
    s = Solution()
    s.longestValidParentheses("(()))())(")

