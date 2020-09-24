#
# @lc app=leetcode.cn id=22 lang=python3
#
# [22] 括号生成
#

# @lc code=start
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        # 第一个位置只能是 '(' 
        result = {'(': [1,1]}  # [1,1] 分别代表：栈内目前数，栈达到过的最多
        for _ in range(n*2-1):  # 既要数目匹配，也要括号匹配
            new_r = {}
            for item in result.items():
                k_str, stack = item
                if stack[1] >= n: # 不能再加（ 了， 加 ）
                    new_r[k_str+')'] = [stack[0]-1,stack[1]]
                    continue
                if stack[0] == 0: # 只能加 （
                    new_r[k_str+'('] = [stack[0]+1, stack[1]+1]
                    continue 
                # （ ）都加
                new_r[k_str+'('] = [stack[0]+1, stack[1]+1] # 加左
                new_r[k_str+')'] = [stack[0]-1,stack[1]] # 加右
            result.clear()
            result = new_r
        return list(result.keys())
# @lc code=end

