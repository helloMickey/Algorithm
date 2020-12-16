#
# @lc app=leetcode.cn id=50 lang=python3
#
# [50] Pow(x, n)
#

# @lc code=start
class Solution:
    def recur(self, x: float, n: int) -> float:
        if n == 1:
            return x
        if n%2 == 0: # 偶数
            return self.recur(x, int(n/2))**2
        else:
            return x*self.recur(x, int(n/2))**2
            
        pass

    def myPow(self, x: float, n: int) -> float:
        """
        处理快速幂本身的计算
        还需要考虑很多边界的条件呀！！！
        """

        if n==0 or x==1:
            return 1
            
        # 边界条件 ！
        if (n <= (- 2**31) or n >= 2**30) and abs(x) > 1:
            return 0

        if n < 0:
            return 1/self.recur(x, -n)
        else:
            return self.recur(x, n)
        
# @lc code=end

