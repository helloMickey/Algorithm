// https://leetcode-cn.com/problems/longest-happy-prefix/

class Solution {
public:
    string longestPrefix(string s) {
        // 求 KMP 算法中的 next 数组
        // a b a b a b
        // 0 0 1 2 3 4

        // len = next[i] 表示 s[0:len+1] = s[i-len+1: i]
        // 当 s[i] 与主串匹配失败时，应从s[ next[i] - 1 ] 处接着与主串继续匹配

        vector<int> next(s.size(), 0);
        
        int j = 1;
        for(int i = 1 ; i<s.size(); i++){
            j = next[i - 1];
            while(j && s[i] != s[j]){
                j = next[j-1];
            }
            if(s[i] == s[j]) next[i] = j + 1; // else 说明 j 为 0，则 next[i]=0
        }

        // for(auto i: next) cout << i << " ";
        // cout << endl;

        return s.substr(0, next[s.size() - 1]);
    }
};