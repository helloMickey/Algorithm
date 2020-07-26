"""
https://leetcode-cn.com/problems/decode-string/
"""
class Solution:
    def bracket_match(self, s:str) -> (int, int):
        """
        return 第一个'[' 以及与之匹配的 ']' 的下标 
        """
        l,r = 0,0
        bkt_count = 0
        for i, char in enumerate(s):
            if char == '[':
                if bkt_count == 0:
                    l = i
                bkt_count += 1

            if char == ']':
                if bkt_count == 1:
                    r = i
                    break
                bkt_count -= 1
        pass
        return l, r

    def decodeString(self, s:str)->str:
        size = len(s)

        for i in range(size):
            if '0' <= s[i] and s[i] <= '9':
                head_s = s[:i]
                
                j = i + 1
                while s[j] <= '9':
                    j += 1
                factor = int(s[i:j])
                # s[j] == '['
                # 截取 与 s[j] '[' 匹配的 ']' 中的内容
                l_bkt, r_bkt = self.bracket_match(s[j:])
                # r_bkt = s.find(']')
                middle_expr = s[j:][l_bkt+1:r_bkt]
                
                middle_s = self.decodeString(middle_expr)
                
                rear_s = self.decodeString(s[j:][r_bkt+1:]) if j + r_bkt + 1 < size else ''
                return head_s + middle_s*factor + rear_s
        pass
        # 没有发现数字（自然也没有[]出现）
        return s 



if __name__ == "__main__":
    s = Solution()
    print(s.decodeString("3[a2[c]]"))
    print(s.decodeString("3[a]2[bc]"))
    
    print(s.decodeString("2[abc]3[cd]ef"))
    pass