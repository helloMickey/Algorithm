// https://leetcode-cn.com/problems/partition-equal-subset-sum/

/*
先求总和sum，然后判断数组中能否选取若干元素使得总和为 sum/2
*/

class Solution {
    vector<vector<short>> dp;
    bool _dfs(vector<int>&nums, int i, int target){
        if(target == 0) return true;
        if(target < 0 || i >= nums.size()) return false;

        if(dp[i][target] != -1) return dp[i][target];
        dp[i][target] =  _dfs(nums, i+1, target)|| _dfs(nums, i+1, target - nums[i]);

        return  dp[i][target];
    }
public:
    bool canPartition_dfs(vector<int>& nums) {
        // sum / 2  => 能够挑选出若干个元素，使得其和为 sum/2
        int sum = 0;
        for(int a : nums) sum += a;

        if(sum%2 != 0) return false;
        int target = sum/2;

        dp = vector<vector<short>>(nums.size(), vector<short>(target+1, -1));
        return _dfs(nums, 0, target);
    }

    bool canPartition(vector<int>& nums) {
        // sum / 2  => 能够挑选出若干个元素，使得其和为 sum/2
        int sum = 0;
        for(int a : nums) sum += a;

        if(sum%2 != 0) return false;
        int target = sum/2;

        // dp[i][j] : 前 i 个数是否能够得到总和为 j
        // dp[i][j] = dp[i-1][j - nums[i-1]] or dp[i-1][j]
        
        vector<vector<bool> > dp(nums.size() + 1, vector<bool>(target + 1, false));
        dp[0][0] = true;
        
        for(int i = 1; i <= nums.size(); i++) 
            if(nums[i-1] <= target) 
                dp[i][nums[i-1]] = true;

        // 在动态规划中，不管是行优先遍历还是列优先遍历，都可以实现状态转移的计算
        // 但是，一般基于滚动数组的优化，只在一种情况下可行 ！！！
        for(int i = 1; i <= nums.size(); i++){
            for(int j = 1; j <= target; j++){
                if(dp[i-1][j])
                    dp[i][j] = true;
                else if(j >= nums[i-1])
                    dp[i][j] = dp[i][j] || dp[i-1][j - nums[i-1]];
            }
        }
        
        /* 列优先遍历
        for(int j = 1; j <= target; j++){
            for(int i = 1; i <= nums.size(); i++){
                if(dp[i-1][j])
                    dp[i][j] = true;
                else if(j >= nums[i-1])
                    dp[i][j] = dp[i][j] || dp[i-1][j - nums[i-1]];
            }
        }
        */

        return dp[nums.size()][target];
    }
};