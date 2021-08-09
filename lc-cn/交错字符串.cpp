// https://leetcode-cn.com/problems/interleaving-string/

/*
方法1 ： DFS + 打表

方法2：动态规划，既然已经写出了方法 1，
定义 f(i, j) 表示 s_1 的前 i 个元素和 s_2 的前 j 个元素是否能交错组成 s_3 的前 i + j 个元素。
其他不难写出这样的状态转移方程： f[i][j] = (f[i-1][j] && s1[i-1]== s3[p]) || (f[i][j-1] && s2[j-1]== s3[p]) , p = i+j-1
*/

class Solution {
    vector<vector<short> > dp; // 打表优化，不然会超时
    string s1, s2, s3;
    bool _dfs(int i, int j, int idx){
		if (i == s1.size()) {
			return s2.substr(j, s2.size() - j + 1) == s3.substr(idx, s3.size() - idx);
		}
		if (j == s2.size()) return s1.substr(i, s1.size() - i) == s3.substr(idx, s3.size() - idx);

        if(dp[i][j] != -1) return dp[i][j];

		bool flag1 = false, flag2 = false;
		if (s1[i] == s3[idx]) {
			flag1 = _dfs(i+1, j, idx+1);
		}
		if (s2[j] == s3[idx]) {
			flag2 = _dfs(i, j+1, idx+1);
		}

        bool res = flag1 || flag2;
        dp[i][j] = res ? 1 : 0;
		return res;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())
            return false;
        dp = vector<vector<short>>(s1.size(), vector<short>(s2.size(), -1));
        // 直接DFS 暴力搜索
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        return _dfs(0, 0, 0);
    }
};
