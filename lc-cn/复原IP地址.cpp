// https://leetcode-cn.com/problems/restore-ip-addresses/

class Solution {
    vector<string> res;
    string num_str;
public:
    void DFS(string cur_ip, int i, int stage){
        if(i >= num_str.size() || stage > 4) return;
        if(stage == 4) {
            if(num_str.size() - i > 1 && num_str.substr(i, num_str.size() - i)[0] == '0') return ; // 字符串中不能有前导0
            int remain_str_num = atoi(num_str.substr(i, num_str.size() - i).c_str());
            if(remain_str_num < 256 && remain_str_num >= 0)
                res.push_back(cur_ip + "." + to_string(remain_str_num));
            return;
        }
        int c = 1;
        int pre_num = atoi(num_str.substr(i, c).c_str());
        while(pre_num >=0 && pre_num < 256 && (i+c) <= num_str.size()){ // 尝试所有可能的前缀
            DFS(cur_ip + (i==0 ? "" : ".") + to_string(pre_num) , i + c, stage + 1);
            c++;
            if(num_str.substr(i, c)[0] == '0') break; // 字符串中不能有前导0
            pre_num = atoi(num_str.substr(i, c).c_str());
            
        }
    }
    vector<string> restoreIpAddresses(string s) {
        num_str = s;
        DFS("", 0, 1);
        return res;
    }
};