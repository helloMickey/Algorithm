// https://leetcode-cn.com/problems/max-consecutive-ones-iii/

// 经典滑动窗口

class Solution {
public:
    // 精简版实现 ！！！
    int longestOnes(vector<int>& nums, int k){
        
        int head = 0, rear = 0;
        int z_c = 0; // 当前窗口中 0 的个数
        
        while(rear < nums.size()){
        
            if(nums[rear] == 0) z_c++;
            
            if(z_c <= k) rear++; // 窗口向右扩张 
            else{
                // 窗口向右滑动
                if(nums[head] == 0) z_c--;
                head++;
                rear++;
            }
        
        }
        return rear - head;
    }

    int longestOnes_(vector<int>& nums, int k) {
        int head = 0, rear = 0;

        int z_c = nums[0]==0 ? 1 : 0; // 当前窗口中 0 的个数
        while(rear < nums.size()){

            while(z_c <= k){
                rear++; // 窗口右扩
                if(rear >= nums.size()) return rear - head;
                if(nums[rear] == 0) z_c++;
            }            
            // 窗口右移动
            if(nums[head] == 0) z_c--;
            head++; rear++;
            if(rear < nums.size() && nums[rear] == 0) z_c++;
        }
        return rear - head;
    }
};