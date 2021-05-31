// https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/

class Solution {
public:
    int findNthDigit(int n) {
        if(n <= 9) return n;
        n -= 10; // 从0开始计数
        int l = 10, u = l*10 - 1; // 10~99
        long c = 2; // 当前区间数字位数
        long inter_c = (u - l + 1)*c; //当前区间字符数
        while(n >= inter_c){ // n 不在该区间内则继续循环
            n -= (u - l + 1)*c;

            l *= 10;
            u = l*10 - 1; // 100 ~ 999
            c++;
            inter_c = (u - l + 1)*c;
        }
        int num = l + n/c; // 确定n位置对应的哪一个整数
        int idx = n%c; // 以及对应该数的第几位
        
        // cout << num << " " << idx << " ";

        auto res = to_string(num)[idx];
        // return std::atoi((const char *)res); // res 为 '0' 时会报错
        return res - '0';

        /*
        vector<int> nums_n; // 记录整数的每一位
        while(num/10){
            nums_n.push_back(num%10);
            num = num/10;
        }
        nums_n.push_back(num%10);
        return nums_n[c - 1 - idx]; // 100 的第0位为 1
        */
    }
};