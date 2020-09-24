"""
https://leetcode-cn.com/problems/valid-parentheses/
"""
class Solution:
    def isValid(self, s: str) -> bool:
        if s == '':
            return True
        dic = {
            '(':-1, ')':1,
            '{':-2, '}':2,
            '[':-3, ']':3
        }
        stack = list()
        stack.append(dic[s[0]])
        for ch in s[1:]:
            if len(stack) == 0:
                stack.append(dic[ch])
                continue
            if (stack[-1] + dic[ch]) == 0 and stack[-1] < dic[ch]: # 括号匹配/顺序也对
                stack.pop()
            else:
                stack.append(dic[ch])
        if len(stack) != 0:
            return False
        return True

if __name__ == "__main__":
    s = Solution()
    s.isValid("(){}}{")