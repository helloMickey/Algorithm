// https://leetcode-cn.com/problems/delete-and-earn/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        // 重复的元素要么被多次选中，要么依次都不会被选中 =》类似 打家劫舍 问题

        // 排序，并统计每个元素个数
        std::sort(nums.begin(), nums.end());
        
        vector<int> uNums;
        vector<int> count;
        auto p = nums.begin();
        int prev_num = *p;
        int prev_count = 0;
        while (p != nums.end())
        {//去重，统计每个重复元素的个数
            if(*p != prev_num){
                uNums.push_back(prev_num);
                count.push_back(prev_count);

                prev_num = *p;
                prev_count = 1;
            }
            else{
                prev_count++;
            }
            p++;
        }
        // 尾部连续相同数的统计
        uNums.push_back(prev_num);
        count.push_back(prev_count);

        // 动态规划
        vector<int> dp(uNums.size(), 0);
        /**
        if nNums[i] - 1 == nNums[i]:
            dp[i] = max(dp[i-2] + uNums[i]* count[i], dp[i-1]);
        else:
            dp[i] = dp[i-1] + uNums[i]* count[i]
        **/
        dp[0] = uNums[0] *  count[0];
        dp[1] = (uNums[1]-1)==uNums[0] ? max(dp[0], uNums[1] * count[1]) : dp[0] + uNums[1] * count[1];
        for (int i = 2; i < uNums.size(); i++)
        {
            if((uNums[i]-1)==uNums[i-1]){
                dp[i] = max(dp[i-2] + uNums[i]* count[i], dp[i-1]);
            }else{
                dp[i] = dp[i-1] + uNums[i]* count[i];
            }
        }
        return dp.back();
    }
};