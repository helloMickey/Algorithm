// https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/

// 排列

class Solution {
public:
    // 避免包含重复字符 "aab"
    vector<string> _pertmutation(vector<char>& remains){
        vector<string> res;
        if(remains.size() == 1){ 
            string ele;
            ele = remains[0]; 
            res.push_back(ele);
            return res;
        }
        unordered_set<char> trved_char;
        for(auto it = remains.begin(); it < remains.end(); it++){
            if(trved_char.find(*it) != trved_char.end()){
                // 该字符已经作为首字母遍历过
                continue;
            }
            trved_char.insert(*it);
            // 不包含 *it 元素的字符数组
            vector<char> cur_remains(remains.begin(), it);
            cur_remains.insert(cur_remains.end(), it+1, remains.end());
            vector<string> cur_res = _pertmutation(cur_remains);
            for(string str:cur_res){
                res.push_back(*it + str);
            }
        }
        return res;
    }
    vector<string> permutation(string s) {
        // 也是一个递归的过程
        vector<char> remains;
        for(char c:s){
            remains.push_back(c);
        }
        return _pertmutation(remains);
    }
};

class Solution_Fast { // 更为高效的解决方案
public:
    vector<string> permutation(string s) {
        vector<string> res;

        dfs(res,s,0);
       
        return res;
    }

    void  dfs(vector<string> &res,string &s,int pos){
        if(pos == s.size())
            res.push_back(s); // 记录一个结果

        for(int i=pos;i<s.size();i++){
            bool flag = true;
            for(int j = pos; j < i; j++)//之前访问过的中存在与当前字母相同的，等效，剪枝
                if(s[j] == s[i])
                    flag = false;
            if(flag){
                swap(s[pos],s[i]);
                dfs(res,s,pos+1);
                swap(s[pos],s[i]);

            }
        }
    }
};