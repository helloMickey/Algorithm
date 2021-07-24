class Solution {
public:
    /*
    最优思路：贪心 + 二分查找
    
    如果我们要使上升子序列尽可能的长，则我们需要让序列上升得尽可能慢，
    因此我们希望每次在上升子序列最后加上的那个数尽可能的小。
    
    基于上面的贪心思路，我们维护一个数组 d[i] ，
    表示长度为 i 的最长上升子序列的末尾元素的最小值，用 len 记录目前最长上升子序列的长度，
    d 中元素一定是递增的。

    如果当前 num[i] > d[len]， 则 len++
    否则，d[j-1] < nums[i] < d[j] ， 更新 d[j] = nums[i]，在相同长度下选择一个更小的末尾。
    */

    // 常规动态规划思路
    int lengthOfLIS(vector<int>& nums){
        // dp[i] 表示，以 nums[i]为结尾的单调子序列长度
        // dp[i] = max{dp[j] + 1, for j in [0, i-1]}
        vector<int> dp(nums.size(), 1);
        int res = 1;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j < i; j++){
                if(nums[j] < nums[i]) 
                    dp[i] = max(dp[j] + 1, dp[i]);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
    // 单调栈的思路有问题啊，[0,1,0,3,2,3]
    int lengthOfLIS_Error(vector<int>& nums) {
        //单调递增栈，记录最大容量
        int res = 1;
        stack<int> n_stk;
        for(int n: nums){
            while(!n_stk.empty() && n <= n_stk.top()){
                n_stk.pop();
            }
            n_stk.push(n);
            if(n_stk.size() > res) res = n_stk.size();
        } 
        return res;
    }
};