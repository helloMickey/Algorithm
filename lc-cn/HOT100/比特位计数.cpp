// https://leetcode-cn.com/problems/counting-bits/

/*
统计一个数 n 二进制中的 1 的个数：

while (x > 0) {
    x &= (x - 1);
    counter++;
}

while(x > 0){
    x = x >> 1;
    counter++;
}
*/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1, 0);
        int offset=0;
        for(int i=1; i <=n; i++){
            if((i & (i - 1)) == 0){ // 2的n次幂
                res[i] = 1;
                offset = i; // 更新 offset
            }else{
                res[i] = res[i - offset] + 1;
            }
        }
        return res;
    }
    vector<int> countBits_solution2(int n) {
        vector<int> bits(n + 1);
        int highBit = 0;
        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) == 0) {
                highBit = i;
            }
            bits[i] = bits[i - highBit] + 1;
        }
        return bits;
    }
};