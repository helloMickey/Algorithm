// https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/

// 给定一个入栈顺序,判断一个序列是否为其可能的出栈序列

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size() == 0) return true;
        stack<int> s;
        int idx = 0, idx_p = 0;
        while(idx < pushed.size()){
            if(s.empty()){ s.push(pushed[idx++]); continue;}
            
            if(s.top() == popped[idx_p]){
                s.pop(); idx_p++;
            }else{
                s.push(pushed[idx++]);   
            }
        }
        // 只能出栈
        while(!s.empty()){
            if(s.top() != popped[idx_p]) return false;
            s.pop(); idx_p++;
        }
        return true;
    }
};