// https://leetcode-cn.com/problems/valid-parenthesis-string/

class Solution {
    string str;
    bool dfs(int lc, int rc, int i){
        // lc rc 为左右非法括号的计数， i为遍历到当前str的位置
        if(i == str.size()){
            if(lc==0 && rc==0) return true;
            return false;
        }
        if(rc > 0) return false; // 出现非法 ')'

        if(str[i] == '('){
            lc++;
        }else if(str[i] == ')'){
            if(lc > 0) lc--;
            // else rc++;
            else return false;
        }else if(str[i] == '*'){
            bool f1, f2, f3;
            
            // * 视为 spec
            f3 = dfs(lc, rc, i+1);
            if(f3) return true;
            
            // * 视为 (
            f1 = dfs(lc+1, rc, i+1);
            if(f1) return true;
            // * 视为 )
            if(lc > 0) f2 = dfs(lc--, rc, i+1);
            else return false;
            if(f2) return true;

            
            return false;
        }

        return dfs( lc,  rc,  i + 1);
    }
public:
    // * 可以替换为 'spec' ')' '(' 三种情况，通过 DFS 进行遍历尝试所有可能情况  => 算法超时了！！！！！！
    bool checkValidString(string s){
        str = s;
        return dfs(0, 0, 0);
    }

    // 只考虑的非法括号的个数，没有考虑能否与 * 匹配
    bool checkValidString_error(string s) {
        int lc=0, rc=0; // 统计多余的左右括号数目
        int sc=0;// 统计出现的星号数
        for(char ch : s){
            if(ch == '(') lc++;
            else if(ch == ')') {
                if(lc > 0) lc--;
                else rc++;
            }
            else if(ch == '*') sc++;
            
            if(rc > 0){// 出现非法 ')'
                if(rc > sc) return false; // 星号不够补 "("
                while(rc--){
                    sc--;
                }
            }
        }
        if((rc+lc) > sc) return false;
        return true;
    }
};