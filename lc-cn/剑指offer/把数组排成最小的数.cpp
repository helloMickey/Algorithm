// https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/

/*
自定义比较函数
*/

class Solution_Easy {
public:
    string minNumber(vector<int>& nums) {
        string res = "";
        // 降序排列， string 默认是按照字符序比较大小的 "303" < "330"
        sort(nums.begin(), nums.end(), [](int x, int y){ return to_string(x) + to_string(y) < to_string(y) + to_string(x); }); 
        for(int i = 0; i < nums.size(); i++)
            res += to_string(nums[i]);
        return res;
    }
};

class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        string res;
        for(int i = 0; i < nums.size(); i++)
            strs.push_back(to_string(nums[i]));
        sort(strs.begin(), strs.end(), [](string& x, string& y){ return x + y < y + x; });
        for(int i = 0; i < strs.size(); i++)
            res.append(strs[i]);
        return res;
    }
};
