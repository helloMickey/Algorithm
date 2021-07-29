// https://leetcode-cn.com/problems/longest-consecutive-sequence/

// 使用哈希表来快速判断一个值是否存在
// 关键在于 O(n) 的时间复杂度

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() < 1) return 0;

        // 用 hash 表存储每一个数，用于快速判断一个值是否存在
        unordered_set<int> hash_st;
        for(int num: nums) hash_st.insert(num);
        int res = 1;
        for(int i=0 ; i < nums.size(); i++){
            int temp_res = 1;
            if(hash_st.find(nums[i] - 1) == hash_st.end()){
                // 该值的前驱值不存在
                int temp_val = nums[i] + 1;
                while(hash_st.find(temp_val) != hash_st.end()){
                    // 统计后续连续长度值
                    temp_val ++;
                    temp_res++;
                }
                res = max(res, temp_res);
            }
            else{
                // 该值的前驱值存在，则一定会被统计到
                continue;
            }
        }
        return res;
    }
};