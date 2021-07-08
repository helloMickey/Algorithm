// https://leetcode-cn.com/problems/maximum-sum-circular-subarray/

class Solution {
public:
    // 动态规划
    int maxSubarraySumCircular(vector<int>&nums){
        if(nums.size()==1) return nums[0];

        vector<int> dp_max(nums.size(), 0); // dp[i] 以nums[i]为结尾的最大和连续子数组
        vector<int> dp_min(nums.size(), 0); // 以nums[i]为结尾的最小和连续子数组
        
        int max_sum = nums[0];
        dp_max[0] = max(0, nums[0]);
        dp_min[0] = min(0, nums[0]);
        
        int sum = nums[0];
        for(int i=1; i<nums.size();i++){
            dp_max[i] = max(dp_max[i-1] + nums[i], nums[i]);
            dp_min[i] = min(dp_min[i-1] + nums[i], nums[i]);

            max_sum = max(max_sum, dp_max[i]);
            sum += nums[i];
        }
        // num[1: n-1] 中的最小连续子序列
        int min_sum = *std::min_element(std::next(dp_min.begin(), 1), std::prev(dp_min.end(), 1));
        // int min_sum = *std::min_element(dp_min.begin() + 1, dp_min.end() - 1);

        return max(max_sum, sum - min_sum); // 不跨越情况，跨越情况
    }

    //暴力 ：O(n^2) 计算每个可能的子数字起始位置
    int _maxSubarraySumCircular(vector<int>& nums) {
        int res = nums[0];
        for(int i=0; i<nums.size();i++){
            int sum = nums[i];
            for(int j = i+1; (j % nums.size()) != i ; j++){
                res = max(res, sum);
                sum += nums[j % nums.size()];
            }
            res = max(res, sum);
        }
        return res; 
    }
};