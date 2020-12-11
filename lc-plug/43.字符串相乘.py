#
# @lc app=leetcode.cn id=43 lang=python3
#
# [43] 字符串相乘
#

# @lc code=start
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "" or num2 == "":
            return "0"
        if "0" in [num1, num2]:
            return "0"

        result = 0
        L1, L2 = len(num1), len(num2)
        for i in range(1, L1+1):
            a = int(num1[-i])
            temp_result = 0
            carry = 0
            for j in range(1, L2+1):
                b = int(num2[-j])
                m = a*b
                temp_result += (m%10 + carry)*(10**(j-1))
                carry = int(m/10)
            temp_result += carry*(10**(L2))  # 剩余的
            result += temp_result*(10**(i - 1))
        
        return str(result)
        
            
# @lc code=end

if __name__ == "__main__":
    s = Solution()
    s.multiply('9', '99')