// https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/

// 核心思路：滑动窗口
// 借助哈希表，判断两个串是否是 异位词


/*
作者：bestblade
链接：https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/solution/hua-dong-chuang-kou-shu-zu-ha-xi-biao-by-r2k2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

//判断两个单词是否相同
bool check(int s[], int p[]) {
    for (int i = 0; i < 26; i++) {
        if (s[i] != p[i]) {
            return false;
        }
    }
    return true;
}

vector<int> findAnagrams(string s, string p) {
    vector<int> res;
    if (p.size() > s.size()) {
        return res;
    }
    //采用数组代替哈希表，速度更快，但是要自己写判断函数
    int s_cnt[26] = { 0 };
    int p_cnt[26] = { 0 };
    for (int i = 0; i < p.size(); ++i) {
        s_cnt[s[i] - 'a']++;
        p_cnt[p[i] - 'a']++;
    }

    if (check(s_cnt,p_cnt)) {
        res.emplace_back(0);
    }

    int l = 0;
    int r = p.size() - 1;

    while (r < s.size() - 1) {
        s_cnt[s[l++] - 'a']--;
        s_cnt[s[++r] - 'a']++;
    
        if (check(s_cnt, p_cnt)) {
            res.emplace_back(l);
        }
    }
    return res;
}