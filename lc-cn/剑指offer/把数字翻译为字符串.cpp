// https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/
/*
可以通过递归的方法解决，也可以通过动态规划的方法解决。
*/

class Solution {
public:
	map<int, int> table;
	int translateNum(int num) {
		if (table.count(num)) { return table[num]; } // 避免重复计算
		// 转化为递归问题
		string s_num = std::to_string(num);
		if (s_num.size() == 2) return atoi(s_num.c_str()) < 26 ? 2 : 1; // 可以拆分 + 不拆分；只能拆分；
		if (s_num.size() == 1) return 1;
        
		// 12258
		int pre2_num = atoi(s_num.substr(0, 2).c_str()); // 取数字前两位 12
		int aft2_num = atoi(s_num.substr(2, s_num.size() - 2).c_str()); // 258
		int aft1_num = atoi(s_num.substr(1, s_num.size() - 1).c_str()); // 2258
		int res = pre2_num < 26 ? translateNum(aft1_num) + translateNum(aft2_num) : translateNum(aft1_num);
		table[num] = res;
		// cout << num << " " << res << endl;
		return res;
	}


	int translateNum_dp(int num) {
        string ch = to_string(num);
        int len = ch.size();
        vector<int> dp(len+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= len; i++){
            int n = (ch[i - 2] - '0') * 10 + (ch[i - 1] - '0');
            if(n >= 10 && n <= 25){
                dp[i] = dp[i - 1] + dp[i - 2];
            }else{
                dp[i] = dp[i - 1];
            }
        }
        return dp[len];
    }
};
