#
# @lc app=leetcode.cn id=38 lang=python3
#
# [38] 外观数列
#

# @lc code=start
class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return '1'
        if n == 2:
            return '11'
        bef_str = self.countAndSay(n-1)
        
        res = ''
        count = 1
        c_s = bef_str[0]
        i = 1
        while i < len(bef_str):
            if bef_str[i] == c_s:
                count += 1
                i += 1
            else: # 前一节重复的数结束了
                res += str(count) + c_s
                c_s = bef_str[i]
                count = 1
                i += 1
                if i == len(bef_str):
                    res += '1' + c_s  # 1 个 c_s
                    return res

        res += str(count) + c_s
        return res
# @lc code=end