#
# @lc app=leetcode.cn id=69 lang=python3
#
# [69] x 的平方根
#

# @lc code=start
class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 1:
            return 1
        if x < 1:
            return 0
        head = 1
        rear = x/2
        while head <= rear:
            mid = int((head+rear)/2)
            if mid**2 == x:
                return mid
            elif mid**2 < x:
                if (mid + 1)**2 > x:
                    return mid
                head = mid + 1
            else:
                rear = mid - 1
                
# @lc code=end

