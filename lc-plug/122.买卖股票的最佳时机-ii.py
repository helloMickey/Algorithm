#
# @lc app=leetcode.cn id=122 lang=python3
#
# [122] 买卖股票的最佳时机 II
#

# 也可以动态规划的方法：
# dp[i][0] 表示第 i 天交易完后手里没有股票的最大利润 = 前一天就没持有 or 前一天持有今天卖出
# dp[i][1] 表示第 i 天交易完后手里持有一支股票的最大利润 = 前一天就持有 or 前一天没有今天刚买入
# （i 从 0 开始）

# dp[i][0] = max{dp[i−1][0], dp[i−1][1] + prices[i]} 
# dp[i][1] = max{dp[i−1][1], dp[i−1][0] − prices[i]}

# 链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/solution/mai-mai-gu-piao-de-zui-jia-shi-ji-ii-by-leetcode-s/

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        """
        因为交易次数不受限，如果可以把所有的上坡全部收集到，一定是利益最大化的
        """
        profit = 0
        for i in range(1, len(prices)):
            if (prices[i] - prices[i-1]) > 0:
                profit += prices[i] - prices[i-1]
        return profit
                
# @lc code=end

