// https://leetcode-cn.com/problems/subarray-sum-equals-k/

/*
思路不正确 => 滑动窗口 

暴力算法复杂度 => O(n^2) 在内层循环的同时计算该区间上的和

要充分利用子数组的连续性。
sum(0, i) - k 等于 0，或者等于 sum(0, j)；

遍历数组nums，计算从第0个元素到当前元素的和，用哈希表保存出现过的累积和sum的次数。
如果sum - k在哈希表中出现过，则代表从当前下标i往前有连续的子数组的和为sum。
时间复杂度为$O(n)$，空间复杂度为$O(n)$。
*/

class Solution { // 滑动窗口法
public:
    int subarraySum(vector<int>& nums, int k){
        // <sum, counter>
        unordered_map<int, int> sum_map; // 因为数组中存在负值，所以可能有多个相同的累计求和值
        sum_map[0] = 1;
        int sum=0, res=0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(sum_map.find(sum - k) != sum_map.end()) res += sum_map[sum-k];
            
            if(sum_map.find(sum) != sum_map.end()) sum_map[sum] += 1; 
            else sum_map[sum] = 1;
        } 
        return res;
    }
    int subarraySum_error(vector<int>& nums, int k) { // 这个实现目前存在点问题
        int head=0, rear = 0;
        int res=0;
        while(head <= rear && rear<nums.size()){
            int cur_sum = accumulate(nums.begin()+head, nums.begin()+rear+1, 0); // 求区间和
            if(cur_sum == k)  {
                res++;
                head++; rear++;
            }
            else if(cur_sum < k){ // 窗口扩张
            // 由于是从左往右开始滑动的，因此窗口一定是向右扩张的。
                rear++;
            }else{ // 窗口缩小
                head++;
            }
        }
        return res;
    }
};