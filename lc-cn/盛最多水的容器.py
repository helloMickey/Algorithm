"""
https://leetcode-cn.com/problems/container-with-most-water/
"""
from typing import *
class Solution:
    """
    S1 思路：
    n*n复杂度，类似于暴力搜索
    对于最左边的墙，找出最右边高于等于它的墙，则为其能围起来的最高高度
    S2 思路：
    O(n)复杂度
    双指针，从两边往中间，对于两者中矮的那一个而言，
    其作为围栏能围住水的最大值，就是当前指针情况了（最边上，指针是不断收缩的）。
    因此指向更矮的指针向内收缩。
    """
    def maxArea(self, height: List[int]) -> int:
        rear = len(height) - 1
        head = 0
        max_volume = -1
        while head < rear:
            if height[head] <= height[rear]:
                # 底 * 高
                cur_volume = (rear - head)* height[head] 
                head += 1
            else:
                cur_volume = (rear - head)* height[rear] 
                rear -= 1
            if cur_volume > max_volume:
                max_volume = cur_volume
        return max_volume
        
if __name__ == "__main__":
    s = Solution()
    s.maxArea([1,8,6,2,5,4,8,3,7])