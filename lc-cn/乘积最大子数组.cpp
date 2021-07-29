// https://leetcode-cn.com/problems/maximum-product-subarray/solution/

/*
暴力算法：O(n^2) 尝试所有的可能区间

实际思路很简单啊啊啊啊！
*/

class Solution {
// 链接：https://leetcode-cn.com/problems/maximum-product-subarray/solution/cheng-ji-zui-da-zi-shu-zu-by-leetcode-solution/
public:
    int maxProduct(vector<int>& nums) {
        int maxF = nums[0], minF = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int mx = maxF, mn = minF;
            maxF = max(mx * nums[i], max(nums[i], mn * nums[i]));
            minF = min(mn * nums[i], min(nums[i], mx * nums[i]));
            ans = max(maxF, ans);
        }
        return ans;
    }
};

// 自己设计的状态和状态转移方程存在问题；
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /*
        dp[i] 以 nums[i] 为结尾的子数组的乘积
        
        if nums[i] > 0 : 
            dp[i] = max(dp[i-1]*nums[i], nums[i])
        else if nums[0] < 0: 
            找到上一个负数位置 j, dp[i] = nums[j]*nums[i] * dp[j-1] * dp[i-1] , 此时dp[i]最小也是0
        else nums[0] == 0 : 
            dp[i] = 0; 
        */
        vector<int> dp(nums.size()+1, 0);
        dp[0] = 1;
        stack<int> neg_idx;
        stack<int> zero_idx;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0) {
                dp[i+1] = 0;
                zero_idx.push(i);
            }
            else if(nums[i] > 0) {
                dp[i+1] = max(dp[i]*nums[i], nums[i]);
            }
            else{ // nums[0] < 0
                if(!neg_idx.empty()){
                    int j = neg_idx.top();
                    if(i-j > 1){
                        
                        if(!zero_idx.empty() && zero_idx.top() > j && zero_idx.top() < i){
                            // j 到 i 之间有可能存在 0 ， 两个负数没法连起来
                            dp[i+1] = 0;
                        }else{
                            // 两个负数可以连起来
                            dp[i+1] = dp[j] > 0 ? dp[j] * nums[j] * dp[i] * nums[i] : nums[j] * dp[i] * nums[i];
                        }
                        
                    }else{
                        // 两个相邻负数
                        dp[i+1] = dp[j] > 0 ? dp[j] * nums[j] * nums[i] : nums[j] * nums[i];
                    }
                    
                }else{ // 第一个出现的负数
                    dp[i+1] = max(dp[i] * nums[i], nums[i]);
                }
                neg_idx.push(i);
            }
            cout << dp[i+1] << " ";
        }

        return *max_element(dp.begin()+1, dp.end());
    }
};