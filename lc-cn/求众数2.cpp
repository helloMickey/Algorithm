// https://leetcode-cn.com/problems/majority-element-ii/

/*
 给定一个大小为 n 的整数数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。

【笔记】摩尔投票法。
该算法用于1/2情况，它说：“在任何数组中，出现次数大于该数组长度一半的值只能有一个。”
那么，改进一下用于1/3。可以着么说：“在任何数组中，出现次数大于该数组长度1/3的值最多只有两个。”
于是，需要定义两个变量。空间复杂度为O(1)。
 */

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // can1和can2具有相同的起点
        int c1 = 0, c2 = 0, can1 = nums[0], can2 = nums[0];
        for (int num : nums) {
            // 投票过程，优先为can1投票
            if (can1 == num) {
                c1++;
                continue;
            }
            // 其次为can2投票
            if (can2 == num) {
                c2++;
                continue;
            }
            
            // can1和can2的投票必须分开，这里是当can1的票数归零时，重新投票
            if (c1 == 0 && num != can2) {
                can1 = num;
                c1++;
                continue;
            }
            
            // can2归零，注意不能和can1相等
            if (c2 == 0 && num != can1) {
                can2 = num;
                c2++;
                continue;
            }
            
            // 没有与can1和can2相等的，那么同时减一票
            c1--;
            c2--;
        }

        // 再计数 -- 两次遍历也满足O(N)， 如果题目中标明一定存在两个超过 1/3 的数，后面的步骤可以不需要，直接返回 can1，can2。
        c1 = 0;
        c2 = 0;
        for (int num : nums) {
            if (can1 == num) c1++;
            if (can2 == num) c2++;
        }
        
        vector<int> res;
        
        if (c1 > nums.size() / 3) res.emplace_back(can1);
        
        // 注意由于一开始起点相同。所以需要排除 can1 == can2的情况
        if (can1 != can2 && c2 > nums.size() / 3) res.emplace_back(can2);

        return res;
    }
};