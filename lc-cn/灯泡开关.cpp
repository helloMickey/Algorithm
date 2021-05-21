// https://leetcode-cn.com/problems/bulb-switcher/submissions/

class Solution {
            /*
        第i个灯泡的反转次数等于它所有因子（包括1和i）的个数，一开始的状态的灭的，只有反转奇数次才会变成亮的，所以只有因子个数为奇数的灯泡序号才会亮。
        只有平方数的因子数为奇数（比如6=1*6,2*3，它们的因子总是成对出现的，而4=1*4,2*2，只有平方数的平方根因子会只出现1次）。
        所以最终答案等于 n 以内（包括n和1）的平方数数量，只要计算sqrt(n)即可
        */
public:
    int bulbSwitch(int n) {
        // n 以内（包括n和1）的平方数数量，只要计算sqrt(n)
        return std::sqrt(n);
    }
};