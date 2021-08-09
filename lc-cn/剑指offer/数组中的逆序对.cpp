// https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/


class Solution {
    /*
    借助归并排序过程统计逆序对的个数；
    */
public:
    int mergeSort(vector<int>& nums, vector<int>& tmp, int l, int r) {
        if (l >= r) {
            return 0;
        }

        int mid = (l + r) / 2;
        int inv_count = mergeSort(nums, tmp, l, mid) + mergeSort(nums, tmp, mid + 1, r);
        
        int i = l, j = mid + 1, pos = l;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[pos] = nums[i];
                ++i;
            }
            else {
                tmp[pos] = nums[j];
                ++j;
                inv_count += (mid - i + 1);   // 统计逆序对个数
            }
            ++pos;
        }
        for (int k = i; k <= mid; ++k) {
            tmp[pos++] = nums[k];
        }
        for (int k = j; k <= r; ++k) {
            tmp[pos++] = nums[k];
        }
        
        copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
        
        return inv_count;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp(n);
        return mergeSort(nums, tmp, 0, n - 1);
    }
};

class Solution_Time {// 暴力算法 => 超时
public:
    int reversePairs1(vector<int>& nums) {
        // 统计冒泡排序过程中的，交换次数
        int res = 0;
        for(int i = 0; i < nums.size() ; i++){
            bool has_swap = false;
            for(int j = 0; j < nums.size() - 1 - i; j++){
                if(nums[j] > nums[j+1]){
                    res++;
                    swap(nums[j], nums[j+1]);
                    has_swap = true;
                }
            }
            if(!has_swap) break;
        }
        return res;
    }

    int reversePairs(vector<int>& nums){
        int i=0, j=0, sum=0;
        for( i=0; i< nums.size(); i++ ){
            for( j=i+1; j < nums.size(); j++ ){
                if( nums[j] < nums[i] ) sum++; // 统计逆序对
            }
        }
        return sum;
    }
};