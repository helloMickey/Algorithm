// https://leetcode-cn.com/problems/palindromic-substrings/solution/hui-wen-zi-chuan-by-leetcode-solution/

/*
暴力算法： => O(n^3)

改进：
1）基于回文中心，然后左右扩展 => O(n^2)， 所有可能的回文中心是 2n-1 个，再在每个中心向左右扩展，记录了能的回文结果数；

2) O(n) 时间复杂度，没看懂原理....
*/


class Solution {
    // 链接：https://leetcode-cn.com/problems/palindromic-substrings/solution/hui-wen-zi-chuan-by-leetcode-solution/
public:
    int countSubstrings(string s) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < 2 * n - 1; ++i) {
            int l = i / 2, r = i / 2 + i % 2;
            while (l >= 0 && r < n && s[l] == s[r]) {
                --l;
                ++r;
                ++ans;
            }
        }
        return ans;
    }
};


class Solution_Error { // 完全错误的思路
public:
    // 暴力 -> O(n^3) 
    // 打表优化 -> O(n^2)  dp[i][j] 记录 ？
    // dp[i][j] 表示 s 中从i到j的字符串中，回文子串的个数
    // dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1] + (s[i]==s[j] ? 1 : 0)
    int countSubstrings(string s) {
        int n = s.size();
        vector< vector<int>> dp(n, vector(n, 0));
        
        for(int i = 0; i < n; i++){
            int j = i;
            dp[i][j] = 1; // 
        }

        for(int j = 1; j < n; j++){
            for(int i = j - 1; i >= 0 ; i--){
                dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1] + (s[i]==s[j] && (dp[i+1][j] == dp[i][j-1] && ) ? 1 : 0);
            }
        }

        return dp[0][s.size()-1];
    }
};