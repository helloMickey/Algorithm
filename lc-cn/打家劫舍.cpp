// 动态规划
// https://leetcode-cn.com/problems/house-robber/

/**
dp[i] 第 i 家过后所能打劫到的最多现金
if 第 i 家选择打劫:
    dp[i] = dp[i-2] + m[i]; // i - 1 家就一定是不能被打劫的
else: // 第 i 家不打劫
    dp[i] = dp[i-1]
所以综合来看：
dp[i] = max(dp[i-2] + m[i], dp[i-1])
**/
#include <vector>
#include <math.h>
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return nums[0];
        }

        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp.back();
    }
};