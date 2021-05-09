// https://leetcode-cn.com/problems/contains-duplicate/comments/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashSet={};
        for(int nm : nums){
            if(hashSet.find(nm) != hashSet.end()){
                return true;
            }else{
                hashSet.insert(nm);
            }
        }
        return false;
    }
};