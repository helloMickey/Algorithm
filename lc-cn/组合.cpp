// https://leetcode-cn.com/problems/combinations/
#include <vector>
using namespace std;
class Solution2 {
public:
    vector<int> temp;
    vector<vector<int> > ans;

    void dfs(int cur, int n, int k) {
        // 剪枝：temp 长度加上区间 [cur, n] 的长度小于 k，不可能构造出长度为 k 的 temp
        if (temp.size() + (n - cur + 1) < k) {
            return;
        }
        // 记录合法的答案
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        // 考虑选择当前位置
        temp.push_back(cur);
        dfs(cur + 1, n, k);
        temp.pop_back();
        // 考虑不选择当前位置
        dfs(cur + 1, n, k);
    }

    vector<vector<int> > combine(int n, int k) {
        dfs(1, n, k);
        return ans;
    }
};

class Solution {
public:
    vector<vector<int> > dfs(vector<int> nums, int k){
        vector<vector<int> > res;

        if(k == 1){
            for(auto num : nums){
                vector<int> comb = {num};
                res.push_back(comb);
            }
            return res;
        }
        if(k == nums.size()){
            res.push_back(nums);
            return res;
        }

        for(auto p = nums.begin(); p != nums.end(); p++){
            auto num = *p;
            
            vector<int> def_nums;// 要进行递归的元素，不包含当前元素，以及之前已经递归过的元素
            //def_nums.insert(def_nums.end(), nums.begin(), p);
            def_nums.insert(def_nums.end(), p+1, nums.end());

            auto cur_res = dfs(def_nums, k - 1);
            for(auto comb : cur_res){
                comb.push_back(num);
                res.push_back(comb);
            }
        }
        return res;
    }
    vector<vector<int> > combine(int n, int k) {
        //注意组合和排列的区别
        // vector<vector<int>> res;
        vector<int> nums;
        int i = 1;
        while(i <= n){
            nums.push_back(i);
            i++;
        }
        return dfs(nums, k);
    }
};