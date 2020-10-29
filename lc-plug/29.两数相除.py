#
# @lc app=leetcode.cn id=29 lang=python3
#
# [29] 两数相除
#

# @lc code=start
class Solution:
    # def divide(self, dividend: int, divisor: int) -> int:
    #     r = int(dividend/divisor)
    #     if r > (2**31 -1):
    #         return 2**31 -1
    #     return r
    def divide(self, dividend: int, divisor: int) -> int:
        '''
        [-2^31, 2^31 - 1]
        两个32为带符号整数相除时， 只有除数为 -1 时，才有可能溢出
        '''
        # 特殊情况处理
        if dividend==-2**31 and divisor == -1:
            return 2**31 - 1

        # 结果符号
        r = 1
        if (divisor<0 and dividend >0) or (divisor>0 and dividend <0):
            r = -1
        dividend, divisor = abs(dividend), abs(divisor)

        if dividend < divisor:
            return 0
        if dividend == divisor:
            return 1*r
        if divisor == 1:
            return dividend*r

        i = 0
        while divisor<<i < dividend:  # ()^2
            i += 1
        
        remain =  dividend - (divisor<<(i-1))
        j = 0
        temp = divisor
        while temp < remain:  # +=
            j += 1
            temp += divisor
        return r*(2**(i-1) + j)
# @lc code=end

if __name__ == "__main__":
    s = Solution()
    s.divide(10, 3)

