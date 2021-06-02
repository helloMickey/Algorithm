// https://leetcode-cn.com/problems/gray-code/

// 在格雷编码中，相邻两个编码之间二进制位只有一位不同

class Solution {
public:
    vector<int> grayCode(int n) {
        /* 存在对称关系：
        n = 2 时：
        0 0
        0 1

        1 1
        1 0

        n = 3 时：
        0 00
        0 01
        0 11
        0 10

        1 10
        1 11
        1 01
        1 00
        */
        if(n == 0) return{0};
        // if(n == 1) return {0, 1}
        vector<int> init = {0, 1};
        int offset = 1;
        while(--n){
            int val = 1 << offset; // 0010, 0100, 1000,,,, 
            for(int i = std::pow(2, offset) - 1; i >=0 ; --i){ //倒序遍历
                int cur_num = val | init[i];
                init.push_back(cur_num);
            }
            offset++;
        }
        return init;
    }
};