/**
 * https://leetcode-cn.com/problems/capacity-to-ship-packages-within-d-days/
 * 在 D 天内将传送带上的所有包裹送达的船的最低运载能力
 * **/

/**
 * https://leetcode-cn.com/problems/koko-eating-bananas/solution/
 * 返回她可以在 H 小时内吃掉所有香蕉的最小速度 K（K 为整数）
 * **/

#include <Vector>
#include <algorithm>
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        //最初不正确的思路： 将 weights 分为 D 段，每段尽可能重量相等
        
        // 二分法尝试不同的运载能力货船，通过判定当前所需天数与D的大小决定二分搜索方向 
        
    }
};