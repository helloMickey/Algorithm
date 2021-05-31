// https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/

// 数学 + 递归
/*
f(n, m) ：长度为n的序列，以0下标开始，向后m个元素，所删除元素的下标
f(n-1, m)：~

f(n, m) = (f(n-1, m) + m) % n;

*/
class Solution {
    int f(int n, int m) {
        if (n == 1) {
            return 0;
        }
        int x = f(n - 1, m);
        return (m + x) % n;
    }
public:
    int lastRemaining(int n, int m) {
        return f(n, m); // 在长度为 0，1，2，，，n 中下标对应删除元素的值
    }
};