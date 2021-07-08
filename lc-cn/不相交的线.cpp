// https://leetcode-cn.com/problems/uncrossed-lines/

// 与 最长公共子序列 相同；

class Solution {
    /*
    dp[i][j] 以 nums1中第i个，nums2第j个为结尾的两个序列中，最大连线数

    状态转移：dp[i][j] = max{
        dp[i-1][j-1] + (nums[i-1] == nums[j-1] ? 1 : 0), // 结尾字符处是否相等
        dp[i-1][j],
        dp[i][j-1]
    }

    */
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n=nums2.size();
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + (nums1[i-1] == nums2[j-1] ? 1 : 0));
            }
        }
        return dp[m][n];
    }
};