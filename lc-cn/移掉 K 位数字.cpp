// https://leetcode-cn.com/problems/remove-k-digits/

/*
思路，从左到右，找第一个比后面大的字符，删除，清零，k次扫描。

其实该思路可以进一步优化 => 使用单调栈，当前元素小于栈顶元素则进行弹出（也就是删掉一个数字）
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
       if(num.length() == k) return "0";
       for(int i = 0; i < k && num.length()>0; i++)
       {
           int idx=0;
           for(int j=1; j < num.length() && num[j] >= num[j-1]; j++) idx=j; // 找到第一个不满足单调不减的数组位置
           
           num.erase(num.begin()+idx); // 为了防止删成空串，在for的条件判断中加上相关判断
           
           while(num.length() > 1 && num[0]=='0')  num.erase(num.begin()); // 清除前导0
       }
       return num.length() > 0 ? num : "0" ;
    }
};