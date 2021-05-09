// https://leetcode-cn.com/problems/contains-duplicate-ii/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // 发现重复元素，记录 i, j 的差值
        unordered_map<int, vector<int> > gapMap; // <num, idx_gap>
        for(int i=0; i<nums.size(); i++){
            int num = nums[i];
            auto ptr = gapMap.find(num);
            if(ptr == gapMap.end()){
                //插入初始元素
                gapMap.insert(make_pair(num, vector<int>()={i}));
            }else{
                vector<int> equalNums = ptr -> second;
                //查看是否有满足条件的gap
                for(auto p = equalNums.begin(); p!= equalNums.end(); p++){
                    if((i - *p) <= k){return true;} //  i 和 j 的差的 绝对值 至多为 k。
                }
                (ptr->second).push_back(i);
            }
        }
        return false;
    }
};