// https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof/

/*
实际很简单，想太复杂了
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0; 
        int res = 0; //最低收益为0
        int min = prices[0];
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] < min) min = prices[i];
            //假设已在最低点买入，那么当前卖出可以赚多少钱呢，是否是最佳收益呢？
            res = res < (prices[i] - min) ? (prices[i] - min) : res;
        }
        return res;
    }
};