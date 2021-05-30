// https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*
        动态规划: dp[j] 以 nums[j] 为结尾的连续子数组的和
        状态转移方程:
            if nums[j] > 0 : max(dp[j-1] + nums[j], nums[j]) // 连加之后反而比比自身还小
            else dp[j]  = max(dp[j-1] + nums[j], nums[j])
        */
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int res = dp[0];
        for(int i = 1; i < nums.size(); ++i){
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            if(dp[i] > res) res = dp[i];
        }
        return res;

    }
};