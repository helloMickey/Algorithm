// https://leetcode-cn.com/problems/subsets/

class Solution {
    vector<vector<int>> res;
    vector<int> temp_stack;
    vector<int> nums_c;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        nums_c = nums;
        dfs(0);
        return res;
    }
    void dfs(int idx){
        temp_stack.push_back(nums_c[idx]); // 选中当前元素        
        if((idx+1) < nums_c.size()){
            dfs(idx+1); // 递归至后一个位置上的元素
        }else{
            res.push_back(temp_stack); 
        }
        
        temp_stack.pop_back(); // 不选中当前时的状态元素
        if((idx+1) < nums_c.size()){
            dfs(idx+1); 
        }else{
            res.push_back(temp_stack);
        }

    }
};

class Solution_Niu {
    /**
作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/subsets/solution/zi-ji-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
     * **/
public:
    vector<int> t;
    vector<vector<int>> ans;

    void dfs(int cur, vector<int>& nums) {
        if (cur == nums.size()) {
            ans.push_back(t);
            return;
        }
        t.push_back(nums[cur]);
        dfs(cur + 1, nums);
        t.pop_back();
        dfs(cur + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return ans;
    }
};
