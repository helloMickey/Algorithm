
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solution/

/*

链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solution/zui-jia-mai-mai-gu-piao-shi-ji-han-leng-dong-qi-4/

官方给的题解并不算好 ！
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int res = 0;
        int len = prices.size();
        // dp[i][0] : 持有股票
        // dp[i][1] : 不持有股票，本日卖出，下一天为冷冻期
        // dp[i][2] : 不持有股票，本日无卖出，下一天非冷冻期
        vector<vector<int> > dp(len, vector<int>(3, 0));

        //初始状态:
        // 1: 第一天持有，只有可能是买入
        dp[0][0] = -prices[0];

        // 其实dp[0][1]、dp[0][2] 都不写，默认为0也对
        // 2. 第0天，相当于当天买入卖出，没有收益，并造成下一天冷冻期，减少选择。综合认为是负收益
        // dp[0][1] = Integer.MIN_VALUE;
        dp[0][1] = 0;

        // 3. 相当于没买入，收益自然为0
        dp[0][2] = 0;

        for (int i = 1; i < len; i++) {
            // 持有股票： 1.昨天持有股票 2.本日买入（条件：昨天不持有，且不是卖出）
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);

            //本日卖出 : (条件:昨天持有)
            dp[i][1] = dp[i - 1][0] + prices[i];

            // 不持有，但也不是卖出 : 1.昨天卖出，不持有  2.昨天没卖出，但也不持有
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
        }

        // 最后一天还持有股票是没有意义的,肯定是不持有的收益高，不用对比 dp[len-1][0]
        return max(dp[len - 1][1], dp[len - 1][2]);
    }
};