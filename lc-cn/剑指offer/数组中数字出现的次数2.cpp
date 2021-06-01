// https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/
/*
考虑数字的二进制形式，对于出现三次的数字，各 二进制位 出现的次数都是 3 的倍数。
因此，统计所有数字的各二进制位中 1 的出现次数，并对 3 求余，结果则为只出现一次的数字。

作者：jyd
链接：https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/solution/mian-shi-ti-56-ii-shu-zu-zhong-shu-zi-chu-xian-d-4/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

#define S2
#ifdef S1
/*  
            ab    ab    ab    ab
    状态机: 00 -> 01 -> 10 -> 00
    真值表:
    c   b   a   b'
    0   0   1   0
    0   0   0   0
    0   1   1   0
    0   1   0   1
    1   0   1   0
    1   0   0   1
    1   1   1   0
    1   1   0   0
    取结果为1的情况：b' = ~ab~c + ~a~bc = ~a(b~c+~bc) = ~a(b^c)
    因此，可以推出: b = b ^ c & ~a

    在更新b之后：
            ab    ab    ab    ab
    状态机: 01 -> 00 -> 10 -> 01
    调换ab: ba    ba    ba    ba
    状态机: 10 -> 00 -> 01 -> 10
    与上述一致，因此，可以推出：a = a ^ c & ~b

*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (int c: nums) {
            b = b ^ c & ~a;
            a = a ^ c & ~b;
        }
        return b;
    }
};
#else
/*
    用一个数组统计1的数目

*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits_num(32, 0);
        const int m = 3;
        for (int num: nums) {
            int index = 0;
            while (num > 1) {
                bits_num[index++] += num & 1;
                num = num/2;
            }
            bits_num[index] += num & 1;
        }
        int b = 0, res = 0;
        for (int bit: bits_num) {
            bit = bit % 3;
            res |= bit<<b;
            ++b;
        }
        return res;
    }
};
#endif