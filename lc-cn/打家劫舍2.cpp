// https://leetcode-cn.com/problems/house-robber-ii/

class Solution {
    /*
    这道题类似：连续子序列最大和，环形连续子序列最大和
    */
    
    int _rob(vector<int>&nums, int i, int j){
        // nums[i:j] 中能够获得的最大收益
        vector<int> dp(nums.size(), 0);
        dp[i] = nums[i]; dp[i+1] = max(nums[i], nums[i+1]);
        for(int c = i+2; c<=j; c++){
            dp[c] = std::max(
                dp[c-1], // 打劫当前家
                nums[c] + dp[c-2] // 不打劫当前家
            );
        }
        return dp[j];
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 2) return max(nums[0], nums[1]);
        if(nums.size() == 1) return nums[0];
        // 是否打劫了最后一家
        return std::max(
            _rob(nums, 1, nums.size()-1), // 是 
            _rob(nums, 0, nums.size()-2) // 否
        );
    }
};