// https://leetcode-cn.com/problems/word-break/

// dp[i]表示字符串s的前i个字符能否拆分成wordDict
class Solution{
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        vector<bool> dp(s.size() + 1, false);
        
        unordered_set<string> m(wordDict.begin(), wordDict.end()); // O(1) 查询时间
        
        dp[0] = true;
        
        for (int i = 1; i <= s.size(); ++i){
            for (int j = 0; j < i; ++j){ // 尝试不同的位置
                if (dp[j] && m.find(s.substr(j, i-j)) != m.end()){ // 只要有一个 j 满足即可
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};


class Solution { // 自己最开始的思路，存在bug
	/*
	存在 bug:
		"dogs"
		["dog","s","gs"]
	没法处理
	*/
public:
	static bool comp(pair<int, int> a, pair<int, int> b) {
		return a.first < b.first; // 升序
	}
	bool verify(vector<std::pair<int, int> >& match_strs, int i, int j, int l, int r) {
		//判断 match_strs 所有区间能否组成 [l, r]
		if (i == j) { // 只剩最后一个区间
			if (l + match_strs[i].second == r) return true;
			else return false;
		}
		if (match_strs[i].first != l) return false; // 区间起始没对齐


		int same_start = i + 1;
		int same_c = 0;
		while (same_start < j && match_strs[same_start].first == match_strs[i].first) {
			// 区间左端点相同
			same_start++;
			same_c++;
		}
		int recur_i = same_start;
		while (same_c >= 0) {
			bool cur_flag = verify(match_strs, recur_i, j, l + match_strs[same_start - 1].second, r);
			if (cur_flag) return true;
			same_start--;
			same_c--;
		}

		return false;
	}
	bool wordBreak(string s, vector<string>& wordDict) {
		// 记录每个在 S 中匹配的起始位置，然后按所有能匹配的单词能否拼成当前单词。

		vector<std::pair<int, int>> match_strs; // 标记匹配的开始和截止下标 [l, r)
		for (string str : wordDict) {
			int pos = s.find(str);

			// if (s.find(str) != string::npos) {
			// 	match_strs.push_back(make_pair(pos, str.size()));
			// }

			while (pos != string::npos) { // 需要考虑单词可以重复匹配
				match_strs.push_back(make_pair(pos, str.size()));
				pos = s.find(str, pos + str.size());
			}
		}
		if (match_strs.size() == 0) return false;

		std::sort(match_strs.begin(), match_strs.end(), comp); // 左区间升序排序
		// for (auto p : match_strs) cout << p.first << " " << p.second << endl;
		// 判断 match_strs 所有区间能否组成 [0, str.size()-1]
		return verify(match_strs, 0, match_strs.size() - 1, 0, s.size());
		// ....
	}
};