// https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/

// 将数组元素放到对应数组下标处

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // 肯定存在重复的元素
        for(int i=0;i<nums.size();i++){
            // nums[i] 存在在 nums[i] - 1 处
            int j = nums[i];
            
            if(nums[i] != (i+1)) nums[i] = -1; // 当前位置元素发生了挪动
            
            while(j != -1 && nums[j - 1] != j){
                int temp = nums[j - 1];
                nums[j-1] = j;
                j = temp;
            }
            
        }
        vector<int> res;
        for(int i=1;i <= nums.size(); i++){
            if(nums[i-1] == -1) res.push_back(i);
        }
        return res;
    }
};