// https://leetcode-cn.com/problems/word-break-ii/

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // 在单词拆分的基础上，进行改造即可
       
        unordered_set<string> wordSet;
        for(string w:wordDict) wordSet.insert(w);

        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        unordered_map<int, vector<string>> res;
        res[0] = vector<string>(1, "");

        for(int i = 1; i <= s.size(); i++){
            res[i] = vector<string>(); // dp[j] && check(s[j:n]) 时 dp[n] 为 true, 将所有可能的 s[j:n] 进行记录
            
            for(int j = 0; j < i; j++){
                string j_str = s.substr(j, i - j);
               
                if(dp[j] && wordSet.find(j_str) != wordSet.end())
                {
                    dp[i] = true;
                    
                    // 此处不再 break 
                    for(string cur_res: res[j])
                        if(cur_res != "") res[i].push_back(cur_res + " " + j_str);
                        else res[i].push_back(j_str);
                    
                }
            }
        }

        if(dp[s.size()]) return res[s.size()];
        else return {};
    }
};