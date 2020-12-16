#
# @lc app=leetcode.cn id=55 lang=python3
#
# [55] 跳跃游戏
#

# @lc code=start
class Solution:
    def BFS(self, idx, nums):
        b = nums[idx]
        for i in range(1, b+1):
            offset = i
            if idx + offset >= len(nums):
                break
            if self.visit[idx+offset]:
                continue
            self.visit[idx+offset] = True
            
            if (b - offset) >= nums[idx+offset]:
                # 剪枝 ： 当前遍历的范围已经覆盖了要递归的范围
                continue

            self.BFS(idx+offset, nums)
        for i in range(1, b+1):
            offset = -i
            if idx + offset < 0:
                break
            if self.visit[idx+offset]:
                continue
            self.visit[idx+offset] = True

            if (b + offset) >= nums[idx+offset]:
                # 剪枝 ： 当前遍历的范围已经覆盖了要递归的范围
                continue

            self.BFS(idx+offset, nums)
        
    def canJump(self, nums: List[int]) -> bool:
        self.visit = [False]*len(nums)
        self.visit[0] = True

        self.BFS(0, nums)

        return self.visit[-1]
# @lc code=end

