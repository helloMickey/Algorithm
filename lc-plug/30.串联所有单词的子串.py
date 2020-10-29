#
# @lc app=leetcode.cn id=30 lang=python3
#
# [30] 串联所有单词的子串
#

# @lc code=start
from typing import *
# import numpy as np
class Solution:

    def matching(self, sub_str:str):
        dic = self.dic.copy()
        for j in range(self.w_n):  # 字串中的所有词
            idx = j*self.w_l 
            cur_w = sub_str[idx:idx+self.w_l]
            if cur_w not in dic:  # 没有这个词
                return False
            elif dic[cur_w] < 1:
                return False
            else:
                dic[cur_w] -= 1  # 扣除一个
        # 最后要所有的词都扣为 0， 说明刚刚好组成一个句子
        for v in dic.values():
            if v != 0:
                return False

        return True
    pass

    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        self.words = words
        self.w_l = w_l = len(words[0])
        self.w_n = w_n = len(words)
        str_l = w_n*w_l

        from collections import defaultdict
        self.dic = defaultdict(int)  # 记录每个词出现的次数
        for w in words:
            self.dic[w] += 1
        
        result = []
        for i in range(len(s)-str_l+1):  # 遍历所有字串
            sub_str = s[i:i+str_l]
            if self.matching(sub_str):
                result.append(i)
        return result
# @lc code=end

# if __name__ == "__main__":
#     s = Solution()
#     s.findSubstring("barfoothefoobarman", ["foo","bar"])