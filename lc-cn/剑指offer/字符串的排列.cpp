// https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/

// DFS 构造排列

class Solution_Fast { // 更为高效的解决方案
public:
    vector<string> permutation(string s) {
        vector<string> res;
        dfs(res,s,0);
        return res;
    }

	void  dfs(vector<string> &res, string &s, int pos) {
		//s[pos, size()-1] 字符串所能构成的排列情况
		if (pos == s.size())
			res.push_back(s); // 记录一个结果

		// abcd 遍历不同的字符作为 string 的头
		for (int i = pos; i < s.size(); i++) { 
			bool flag = true;
			//之前选中作为头字符的，与当前字符相同 => 结果是等效，剪枝，跳过 DFS
			for (int j = pos; j < i; j++)
				if (s[j] == s[i])
					flag = false;
			
			if (flag) {
				swap(s[pos], s[i]); // 替换至首位
				dfs(res, s, pos + 1);
				swap(s[pos], s[i]); // 恢复

			}
		}
	}
};

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