#
# @lc app=leetcode.cn id=122 lang=python3
#
# [122] 买卖股票的最佳时机 II
#

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

