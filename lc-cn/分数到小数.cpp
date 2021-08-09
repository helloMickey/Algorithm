// https://leetcode-cn.com/problems/fraction-to-recurring-decimal/

// 如果余数出现重复则对应小数点后的小数也会重复

class Solution {
public:
    string fractionToDecimal(int num, int deno) {
        long numerator = num, denominator = deno;
        // cout << sizeof(int) << " "<< sizeof(long);
        
        // 符号位
        bool pos_sign = numerator * denominator >= 0 ? true : false;
        numerator = abs(numerator);
        denominator = abs(denominator);

        string res = pos_sign ? "" : "-";
        res += to_string(numerator / denominator);
        
        numerator = numerator % denominator;
        int remain = numerator; // 余数
        
        if(remain == 0) return res;
        res += '.';

        int idx = res.size();
        unordered_map<int, int> remain_rec; // 记录余数出现的位置，用于处理除不尽的情况 
        
        remain_rec[remain] = idx; // 小数点后第一位
        int mult; // 商
        
        while(true){
            numerator *= 10;
            while(numerator/denominator < 1){
                res += '0';
                idx += 1;
                numerator *= 10;
            }
            mult = numerator / denominator;
            remain = numerator % denominator;
            
            res += to_string(mult);
            idx++;

            if(remain == 0)
                return res;

            if(remain_rec.count(remain)){
                // 循环小数
                res.insert(remain_rec[remain], "(");
                res += ')';
                return res;
            }
            remain_rec[remain] = idx;
            numerator = remain;
        }
    }
};