// https://leetcode-cn.com/problems/edit-distance/

/*
方法一： 基于递归的方法
基于递归的方法比较容易想到，递归尝试所有可能的情况，但是其中存在大量的重复计算情况，
可以通过打表来优化时间复杂度

方法二： 动态规划
dp[i][j] 表示 w1 种前 i 个字符组成的字符串， 到 w2 种前 j 的字符组成的字符串，所需的最小编辑次数
则，状态转移方程：

if(w1[i-1] == w2[j-1]): // 如果 w1第 i 个字符，等于 w2 第 j 个字符
    dp[i][j] = dp[i-1][j-1]
else:
    有多种可能的编辑情况，去编辑次数最小的一个

    dp[i][j] = min( dp[i-1][j] + 1,   // w1[i-1] 进行删除编辑
                    dp[i-1][j-1] + 1, // 替换编辑
                    dp[i][j-1] + 1,  // 插入编辑
                )

*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size(), l2 = word2.size();
        // 动态规划，dp[i][j] 表示 w1 种前 i 个字符组成的字符串， 到 w2 种前 j 的字符组成的字符串，所需的最小编辑次数
        vector<vector<int> > dp(l1+1, vector(l2+1, 0));
        // 初始状态构造
        for(int i = 0; i <= l1; i++){// 从word1构造空串
            dp[i][0] = i; // 全删
        }
        for(int j = 0; j <= l2; j++){// 从空串word1构造word2
            dp[0][j] = j; // 插入
        }
        for(int i = 1; i <= l1; i++){
            for(int j = 1; j <= l2; j++){
                if(word1[i] == word2[j]) {
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    int temp[3] = {
                        dp[i-1][j] + 1,   // w1[i] 进行删除编辑
                        dp[i-1][j-1] + 1, // 替换编辑
                        dp[i][j-1] + 1,  // 插入编辑
                    };
                    dp[i][j] = *std::min_element(temp, temp+3);
                }
            }
        }
        return dp[l1][l2];
    }
};