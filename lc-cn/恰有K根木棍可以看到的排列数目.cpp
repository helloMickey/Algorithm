// https://leetcode-cn.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible/


class Solution {
    /*
    f(i,j) 表示，i 个数的排列中，能看到 j 个，的情况个数
    f(i,j) = f(i−1,j−1) + (i−1)⋅f(i−1,j)
    
    dp[i][j] = dp[i-1][j-1] + dp[i-1][j] * (i-1)
    
    利用滚动数组，进行进行空间优化
    */
public:
    int rearrangeSticks(int n, int k) {
        int MOD = 1e9 + 7;
        vector<int> dp(k+1);
        for(int i=1; i<=n; ++i)
        {
            dp[0] = i==1 ? 1 : 0;
            for(int j=k; j>=1; --j)
            {
                dp[j] = (dp[j-1]%MOD + (long long)(i-1)*dp[j]%MOD)%MOD; 
            }
        }
        return dp[k];
    }
};