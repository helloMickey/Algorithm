// https://leetcode-cn.com/problems/maximum-ice-cream-bars/
// DP 陷阱

class Solution {
    // 这个快排实现会超时 😭😭😭
    void quick_sort(vector<int>& nums, int i, int j){
        if(i >= j) return;
        // 取基准
        int pivot_nums = nums[i], c = i+1, high = j;
        // 按照基准划分，左小右大
        while(c < high){
            if(nums[c] > pivot_nums) {
                swap(nums[c], nums[high]);
                high--;
            }
            else c++;
        }
        int pivot;
        if(nums[high] > pivot_nums) {swap(nums[high-1], nums[i]); pivot = high-1;}
        else {swap(nums[high], nums[i]); pivot = high;}
        
        // 递归
        quick_sort(nums, i, pivot-1);
        quick_sort(nums, pivot+1, j);
    }
public:
    // 正确思路： 排序 + 贪心
    int maxIceCream(vector<int>& costs, int coins){
        //sort(costs.begin(), costs.end());
        quick_sort(costs, 0, costs.size()-1);

        int sum=0, counter=0, i=0;
        while(sum < coins && i < costs.size()){
            sum += costs[i]; 
            counter++;
            i++;
        }
        if(sum > coins) counter--;

        return counter;
    }
    // short dp[100000001][100001];
    // 一顿操作猛如虎，原来不是用DP
    int _maxIceCream(vector<int>& costs, int coins) {
        // dp[c][i] c 现金， 在前 i 个物品中，可以买到的雪糕最大个数
        // dp[c][i] = max(dp[c-w[i]][i-1] + 1, dp[c][i-1]), 买或不买第i个物品

        vector<vector<int> > dp(coins + 1, vector(costs.size()+1, 0));
        // memset(dp, 0, sizeof(dp));

        for(int i = 1; i <= costs.size(); i++){
            for(int r = 1; r <= coins; r++){
                if(r < costs[i]) continue; // 卖不起 dp[r][i] = 0

                int i_cost = costs[i-1]; // 当前i物品的价格
                dp[r][i] = max((int)dp[r - i_cost][i-1] + 1, (int)dp[r][i-1]); 
            }

        }

        return dp[coins][costs.size()];
    }
};