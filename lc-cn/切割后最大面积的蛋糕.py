"""
https://leetcode-cn.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
"""
from typing import *

class Solution:
    def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:
        horizontalCuts.sort()
        verticalCuts.sort()
        horizontalCuts.append(h)  # 在最后添加上蛋糕的最边缘位置
        verticalCuts.append(w)
        max_margin_v, max_margin_h = 0, 0
        prev_h = 0
        for h_i in horizontalCuts:
            cur_margin = h_i - prev_h
            if cur_margin > max_margin_v:
                max_margin_v = cur_margin
            prev_h = h_i

        prev_w = 0
        for w_i in verticalCuts:
            cur_margin = w_i - prev_w
            if cur_margin > max_margin_h:
                max_margin_h = cur_margin

            prev_w = w_i
        
        return (max_margin_h * max_margin_v) % int(1E9 + 7)


if __name__ == "__main__":
    s = Solution()
    print(s.maxArea(5,4,[3,1],[1]))
    pass