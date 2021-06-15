// https://leetcode-cn.com/problems/find-all-good-strings/

// 数位 DP

/*
作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/find-all-good-strings/solution/zhao-dao-suo-you-hao-zi-fu-chuan-by-leetcode-solut/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
private:
    // 这是用来帮助计算关于 stats 的转移函数的 fail 数组
    vector<int> fail;
    // 这是存储动态规划结果的数组
    // 维度从左到右分别为 pos, stats, bound
    int f[500][50][4];
    // 这是存储转移函数结果的数组
    // 两个维度分别为 stats 和 d
    int trans[50][26];
    static constexpr int mod = 1000000007;
    string s1, s2, evil;

public:
    // 这是计算关于 stats 的转移函数
    // 输入为 stats 和 d
    // 输出为转移的结果 g_s(stats, d)
    int getTrans(int stats, char ch) {
        // 如果之前计算过该转移函数就直接返回结果
        if (trans[stats][ch - 97] != -1) {
            return trans[stats][ch - 97];
        }
        // 这是 KMP 算法的一部分
        // 把 evil 看作「模式串」，stats 看作「主串」匹配到的位置
        while (stats && evil[stats] != ch) {
            stats = fail[stats - 1];
        }
        // 存储结果并返回
        return trans[stats][ch - 97] = (evil[stats] == ch ? stats + 1 : 0);
    }

    // 这是用来进行记忆化搜索的函数
    // 输入为 pos, stats 和 bound
    // 输出为 f[pos][stats][bound]
    int dfs(int pos, int stats, int bound) {
        // 如果匹配到了 evil 的末尾，说明字符串不满足要求了，返回 0
        if (stats == evil.size()) {
            return 0;
        }

        // 如果匹配到了上下界的末尾，说明找到了一个满足要求的字符串，返回 1
        if (pos == s1.size()) {
            return 1;
        }

        // 记忆化搜索的关键，如果之前计算过该状态就直接返回结果
        if (f[pos][stats][bound] != -1) {
            return f[pos][stats][bound];
        }
        
        // 将当前状态初始化，因为未初始化的状态值为 -1
        f[pos][stats][bound] = 0;
        
        // 计算第 pos 位可枚举的字符下界
        char l = (bound & 1 ? s1[pos] : 'a'); // 此处直接进行了限定，并不是 'a' ~ s2[pos] or 'z'
        
        // 计算第 pos 位可枚举的字符上界
        char r = (bound & 2 ? s2[pos] : 'z');
        
        for (char ch = l; ch <= r; ++ch) {
            int nxt_stats = getTrans(stats, ch);
            // 这里写得较为复杂
            // 本质上就是关于 bound 的转移函数
            // 可以根据自己的理解编写
            
            int nxt_bound = (bound & 1 ? ch == s1[pos] : 0) ^ (bound & 2 ? (ch == s2[pos]) << 1 : 0);
            f[pos][stats][bound] += dfs(pos + 1, nxt_stats, nxt_bound);
            f[pos][stats][bound] %= mod;
        }
        return f[pos][stats][bound];
    }

    int findGoodStrings(int n, string _s1, string _s2, string _evil) {
        s1 = _s1;
        s2 = _s2;
        evil = _evil;

        int m = evil.size();
        fail.resize(m);
        
        // 这是 KMP 算法的一部分
        // 把「evil」看作模式串，得到它的 fail[] 数组
        for (int i = 1; i < m; ++i) {
            int j = fail[i - 1];
            while (j && evil[j] != evil[i]) {
                j = fail[j - 1];
            }
            if (evil[j] == evil[i]) {
                fail[i] = j + 1;
            }
        }
        
        // 将未搜索过的动态规划状态置为 -1
        memset(f, -1, sizeof(f));
        
        // 将未计算过的转移函数置为 -1
        memset(trans, -1, sizeof(trans));
        
        // 答案即为 f[0][0][3]
        return dfs(0, 0, 3);
    }
};

class Solution {
    string bound;
    vector<vector<int> > dp;
    int dfs(int pos, string pre_str, char cur ,bool flag){
        // pos 表示str中的第几位，flag表示是否沿着区间上限制，
        // pre_str 表示前面的比遍历过的几个字符, cur 表示当前字符
        if(!pos) return -1;
        if(!flag && dp[pos][cur - 'a'] != -1) return dp[pos][cur-'a'];

        int res = 0; // 结果记录；
        int K = flag ? bound[pos] - 'a': 26;
        for(int i=0; i < K , i++){
            char temp_cur = 'a' + i;
            res += dfs(pos-1, pre_str + temp_cur, temp_cur, flag && i==(K-1) );
        }
        if(!flag) dp[pos][cur] = res;
        return res;
    }
    int solve(string str){
        // 从“ ” 到 str 中的好字符串个数

    }
public:
    int findGoodStrings(int n, string s1, string s2, string evil) {
        // dp[n+1][26] 第 i 位，且当前字符位 ch 的好字符串数
        int n = s1.size();
        dp = vector<vector<int> >(n+1, vecot(26, -1)); // (n+1) * 26 的二维矩阵
        s1[s1.size() - 1] = s1[s1.size() - 1] - 1;
        return solve(s2) - solve(s1);
    }
};




