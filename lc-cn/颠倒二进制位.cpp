// https://leetcode-cn.com/problems/reverse-bits/
// https://leetcode-cn.com/problems/reverse-bits/solution/dian-dao-er-jin-zhi-wei-by-leetcode-solu-yhxz/
# define uint32_t unsigned

class Solution
{
private:
    /* data */
public:
    const uint32_t M1 = 0x55555555; // 01010101010101010101010101010101
    const uint32_t M2 = 0x33333333; // 00110011001100110011001100110011
    const uint32_t M4 = 0x0f0f0f0f; // 00001111000011110000111100001111
    const uint32_t M8 = 0x00ff00ff; // 00000000111111110000000011111111

    uint32_t reverseBits(uint32_t n){
        n = (n & M1) << 1 | (n >> 1) & M1;
        n = (n & M2) << 2 | (n >> 2) & M2;
        n = (n & M4) << 4 | (n >> 4) & M4;
        n = (n & M8) << 8 | (n >> 8) & M8;
        return n << 16 | n >> 16;
    } 
};

