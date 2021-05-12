// https://leetcode-cn.com/problems/summary-ranges/comments/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        // O(n) 时间复杂度
        vector<string> res = {};
        auto p = nums.begin();
        while(p != nums.end()){
            long l = *p; // 设置为long 防止++过后溢出
            long temp = l;
            string gap = "" + to_string(l);
            // 取出一个连续的区间
            do{
                p++;
                temp++;
            }while(p!=nums.end() && *p==temp);

            // 这里不连续了
            if(temp == l+1){
                res.push_back(gap); // 单个值
            }else{
                gap += "->" + to_string(temp-1); //区间值
                res.push_back(gap);
            }
            
        }
        return res;
    }
};