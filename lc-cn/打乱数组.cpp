// https://leetcode-cn.com/problems/shuffle-an-array/

/*
对于大小为N的数组，随机shuffle的可能结果情况就是 n! 
那么所实现的shuffle算法，就要保证可能的结果情况是 n!
*/

class Solution {
    vector<int> _nums;
public:
    Solution(vector<int>& nums): _nums(nums){}

    vector<int> reset() {
        return _nums;

    }

    vector<int> shuffle() {
        vector<int> _shuffle_nums(_nums);
        // srand(time(0)); // 不能在shuffle函数中加随机数种子，因为如果调用shuffle()过快，导致随机数相同，但可以在构造函
        int N = _shuffle_nums.size();
        for(int i=0; i < N; i++){
            int j = rand()%(N - i) + i; // [i, size-1] 区间内的随机数
            // cout << j << " ";
            swap(_shuffle_nums[i], _shuffle_nums[j]);
        }
        // cout << endl;
        return _shuffle_nums;
    }
};