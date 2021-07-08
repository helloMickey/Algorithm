// https://leetcode-cn.com/problems/remove-invalid-parentheses/

/*
首先确立左右括号中各自要删除的个数，
然后再通过 DFS 尝试所有可能的删除情况。 
*/

class Solution {
    int leftC, rightC;
    unordered_set<string> res; // 自动具备去重的功能，因为内置的string重载过 == 比较操作符
    string str;

    void dfs(int i, int lc, int rc, string tempStr){
        // i 当前遍历位置，lc rc 表示已经遍历过的左右括号的数目
        // tempStr为构造的结果
        if(i == str.size()) {
            if(lc == rc) res.insert(tempStr);
            return;
        }
        if(rc > lc) return; // 剪枝：当前构造的字符串已经不合法, 退出搜索

        if(str[i] == '('){
            int temp = leftC;
            if(leftC > 0) {
                leftC--; // 剔除；
                dfs(i+1, lc, rc, tempStr);
            }
            leftC = temp; // 不剔除;
            dfs(i+1, lc+1, rc, tempStr + '(');
        }else if(str[i] == ')'){
            int temp = rightC;
            if(rightC > 0) {
                rightC--; // 剔除；
                dfs(i+1, lc, rc, tempStr);
            }
            rightC = temp; // 不剔除;
            dfs(i+1, lc, rc+1, tempStr + ')');
        }else{
            dfs(i+1, lc, rc, tempStr + str[i]);
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {

        int leftC=0, rightC=0; //计算无效的左右括号
        for(char ch : s){
            if(ch == '(') leftC++;
            else if(ch == ')'){
                if(leftC == 0) rightC++;
                else leftC--; // 一个右括号出现可以抵销之前遇到的左括号
            }
        }
        this->leftC = leftC; this->rightC = rightC;
        str = s;

        dfs(0, 0, 0, "");

        vector<string> v_res;
        for(string s:res){
            v_res.emplace_back(s);
        }
        return v_res;
    }
};