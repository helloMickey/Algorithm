#
# @lc app=leetcode.cn id=71 lang=python3
#
# [71] 简化路径
#

# @lc code=start
class Solution:
    def simplifyPath(self, path: str) -> str:
        # 删除多余 /
        strs = [s for s in path.split('/') if s!='/' and s!=""]
        stack = []
        for s in strs:
            if s == '.':
                continue
            elif s=='..':  # 返回上一级
                if len(stack) > 0:
                    stack.pop()
            else:
                stack.append(s)
                
        return '/' + '/'.join(stack)
# @lc code=end

