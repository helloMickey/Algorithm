// https://leetcode-cn.com/problems/basic-calculator/

class Solution {
    int _cal(int a, int b, char op){
        switch(op){
            case '+': 
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                return a / b;
            default:
                return 0;
        }
    }
public:
    int calculate(string s) {
        // + -  字符，
        // * /  spc结果进行弹出, 对栈进行弹出计算表达式结果
        
        stack<int> nums;
        stack<char> ops;
        string cur_num = "";
        for(char ch: s){
            if(ch >= '0' || ch <= '9'){
                cur_num += ch;
            }else{
                if(cur_num != "") {
                    nums.push(atoi(cur_num.c_str())); // 数字入栈
                    cur_num = "";
                }
                if(ch == '+' || ch == '-' || ch == ' '){
                    // 弹出前缀计算表达
                    while(!ops.empty()){
                        // 操作符
                        char cur_op = ops.top(); ops.pop();
                        // 操作数
                        int b = nums.top(); nums.pop();
                        int a = nums.top(); nums.pop();
                        int res = _cal(a, b, cur_op);
                        nums.push(res);
                    }
                    if(ch != ' ') ops.push(ch); // 操作符入栈
                }
                else{// * /
                    ops.push(ch);
                }
            }
        }
        while(!ops.empty()){
            char cur_op = ops.top(); ops.pop();
            // 操作数
            int b = nums.top(); nums.pop();
            int a = nums.top(); nums.pop();
            int res = _cal(a, b, cur_op);
            nums.push(res);
        }
        return nums.top();
    }
};