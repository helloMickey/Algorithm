// https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/

/*
先对所有数字进行一次异或，得到两个出现一次的数字的异或值res（a^b^c^c = a^b = res 相同数字异或结果为 0， 0与任何数异或结果为该数本身）。
在异或结果res的二进制中找到任意为 1 的位。
根据这一位对所有的数字进行分组（相同的数字与res异或后肯定位于同一组，因为 a^b = res, a,b 肯定位于不同的组）。
在每个组内进行异或操作，得到两个数字。
*/

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int ret = 0;
        for (int n : nums)
            ret ^= n;
        int div = 1;
        while ((div & ret) == 0) // 找到 ret 中从右到左第一个为 1 的二进制位 
            div <<= 1;
        int a = 0, b = 0;
        for (int n : nums)
            if (div & n) // 分组并同时在组内进行异或
                a ^= n;
            else
                b ^= n;
        return vector<int>{a, b};
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/solution/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-by-leetcode/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。