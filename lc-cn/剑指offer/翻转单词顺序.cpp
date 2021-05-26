// https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof/

class Solution {
public:
    string reverseWords(string s) {
        // string 按照空格进行划分
        string res = "";
        int end = 0, start = 0;
        while(end != string::npos){
            end = s.find(" ", start);
            string subs = s.substr(start, end - start);
            if(subs != " " && subs != ""){
                res = subs + " " + res;
                // cout << subs <<endl;
            }
            // cout << end << endl;
            start = end + 1;
        }
        return res.substr(0, res.size()-1); // 最后的空格不要
    }
};