from collections import deque
class Solution:
    # 滑动窗口
    def lengthOfLongestSubstring(self, s:str) -> str:
        hash_tab = {}  # 用于查询一个字符是否存在，以及其对应的下标
        size = len(s)
        r = 0
        idx = 0
        l_bound = 0
        while idx < size:
            c = s[idx]
            if (hash_tab.get(c) is None) or (hash_tab.get(c) < l_bound): 
                # 不存在该字符， 或存在 但是在窗口之外
                r = max(idx - l_bound + 1, r) # 更新最长长度，包括该字符
                # hash_tab[c] = idx
                pass
            else:  # 窗口中存在该词
                r = max(idx - l_bound, r) # 更新最长长度，不包括该字符
                l_bound = hash_tab.get(c)+1 # 窗口前移到该字符上一次出现的位置的后一位
            hash_tab[c] = idx
            idx += 1
            
        return r

    # 暴力优化
    def lengthOfLongestSubstring_2(self, s: str) -> int:
        r = 0
        for i in range(0, len(s)):
            temp_s = s[i]
            max_l = 1
            for j in range(i+1, len(s)):
                idx = temp_s.find(s[j])
                if idx is -1: # 不存在
                    temp_s += s[j]
                    max_l += 1
                else: # 存在
                    temp_s += s[j]
                    temp_s[idx+1:]  # 截取
                    i = idx + 1
                    break
            r = max(r, max_l)
        return 
    # 暴力
    def lengthOfLongestSubstring_1(self, s: str) -> int:
        r = 0
        for i in range(0, len(s)):
            temp_s = s[i]
            max_l = 1
            for j in range(i+1, len(s)):
                if s[j] not in temp_s:
                    temp_s += s[j]
                    max_l += 1
                else:
                    break
            r = max(r, max_l)
        return r

if __name__ == "__main__":
    s = Solution()
    s.lengthOfLongestSubstring("abced")