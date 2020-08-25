"""
https://leetcode-cn.com/problems/regular-expression-matching/
"""

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if p == '':
            return s == ''
        first_ch_match = (len(s) > 0) and p[0] in {s[0], '.'}
        if len(p) >= 2 and p[1] == '*':  
            # 不知道 * 会重复多少次（0次或者更多次）
            return self.isMatch(s, p[2:]) or (first_ch_match and self.isMatch(s[1:], p))
        else:
             # 没有*的情况下简单
            return first_ch_match and self.isMatch(s[1:], p[1:])

    """
    作者：dz-lee
    链接：https://leetcode-cn.com/problems/regular-expression-matching/solution/jian-ming-qing-xi-xie-fa-python3xiang-xi-zhu-shi-b/
    来源：力扣（LeetCode）
    著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    """
    def isMatch_(self, s: str, p: str) -> bool:
        if not p: return not s  # 结束条件

        first_match = (len(s) > 0) and p[0] in {s[0], '.'}
        # 先处理 `*`
        if len(p) >=2 and p[1] == '*':
            # 匹配0个 | 多个
            return self.isMatch(s, p[2:]) or (first_match and self.isMatch(s[1:], p))
        
        # 处理 `.` ，匹配一个
        return first_match and self.isMatch(s[1:], p[1:])
if __name__ == "__main__":
    s = Solution()
    print(s.isMatch("ab", ".*c"))
            
                
                