#
# @lc app=leetcode.cn id=121 lang=python3
#
# [121] 买卖股票的最佳时机
#

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if prices == []:
            return 0
        min_p = [prices[0]]  # 截至到目前的最低价
        for i in range(1, len(prices)):
            if prices[i] < min_p[-1]:
                min_p.append(prices[i])
            else:
                min_p.append(min_p[-1])

        max_p = [prices[-1]] # 从这天之后的最高价
        for i in range(2, len(prices)+1):
            if prices[-i] > max_p[0]:
                max_p.insert(0, prices[-i])
            else:
                max_p.insert(0, max_p[0])
        
        max_profit = 0
        for i in range(len(prices)):
            if (max_p[i] - min_p[i]) > max_profit:
                max_profit = max_p[i] - min_p[i]

        return max_profit
# @lc code=end

