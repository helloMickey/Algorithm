// https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/
/*
这题位运算还是背下来吧，毕竟位运算这种模拟加法用法基本就这题，很容易就忘掉。。。。。

^ 亦或 相当于 无进位的求和， 想象10进制下的模拟情况：（如:19+1=20；无进位求和就是10，而非20；因为它不管进位情况）
& 与 相当于 求每位的进位数， 先看定义：1&1=1；1&0=0；0&0=0；即都为1的时候才为1，正好可以模拟进位数的情况,还是想象10进制下模拟情况：（9+1=10，如果是用&的思路来处理，则9+1得到的进位数为1，而不是10，所以要用<<1向左再移动一位，这样就变为10了）；

这样公式就是：（a^b) ^ ((a&b)<<1) 即：每次无进位求 + 每次得到的进位数。我们需要不断重复这个过程，直到进位数为0为止；
*/

class Solution {
public:
    int add(int a, int b) {
        int sum = a^b;//sum是a和b的无进位和
        int carry = ((unsigned int)(a&b)<<1);//进位
        while(carry != 0){
            int oralSum = sum;//保存sum没有加进位之前的值
            sum = sum ^ carry;//sum加上进位
            carry = ((unsigned int)(oralSum & carry) << 1);//更新本次运算产生的进位
        }
        return sum;
    }
};

class Solution { // 递归写法
public:
    int add(int a, int b) {
        if(b == 0){
            return a;
        }
        return add(a^b, (unsigned int)(a & b) << 1); // 无进位加 + 进位加
    }
};