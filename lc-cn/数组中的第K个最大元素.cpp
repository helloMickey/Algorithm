// https://leetcode-cn.com/problems/kth-largest-element-in-an-array/submissions/

// 因为快排每次划分之后，会确定一个元素的最终位置（基准元素）

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        int i = 0, j = nums.size()-1;
        while(i <= j){
            int pivot_num = nums[i];
            int low = i+1, high=j;
            while(low < high){ // 降序排序
                if(nums[low] > pivot_num) low++;
                else{
                    swap(nums[low], nums[high]);
                    high--;
                }
            }
            // low 与 high 重合
            int pivot = nums[high] < pivot_num ? high-1 : high; // 基准
            swap(nums[i], nums[pivot]);

            if(pivot == (k-1)) return pivot_num; // 基准处恰好是目标第k大的元素
            
            // 分治，此处只用分治一边即可
            if(pivot < (k-1)) i = pivot + 1;
            else j = pivot - 1;
        }
        return -1;
    }
};