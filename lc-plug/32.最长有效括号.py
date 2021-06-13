#
# @lc app=leetcode.cn id=32 lang=python3
#
# [32] 最长有效括号
#

"""
我们定义 dp[i] 表示以下标 i 字符结尾的最长有效括号的长度。

dp 数组全部初始化为 0 。显然有效的子串一定以 ‘)’ 结尾，因此我们可以知道以 ‘(’ 结尾的子串对应的 dp 值必定为 0 ，
我们只需要求解 ‘)’ 在 dp 数组中对应位置的值。

转移方程：

s[i]=‘)’ 且 s[i−1]=‘(’，也就是字符串形如 “……()”，我们可以推出：dp[i]=dp[i−2]+2
我们可以进行这样的转移，是因为结束部分的 "()" 是一个有效子字符串，并且将之前有效子字符串的长度增加了 2 。

s[i]=‘)’ 且 s[i−1]=‘)’，也就是字符串形如 “……))”，我们可以推出：
如果 s[i− dp[i−1] −1]=‘(’，那么 dp[i]=dp[i−1]+dp[i−dp[i−1]−2]+2

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/longest-valid-parentheses/solution/zui-chang-you-xiao-gua-hao-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
"""

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

