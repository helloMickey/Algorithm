#
# @lc app=leetcode.cn id=49 lang=python3
#
# [49] 字母异位词分组
#
from typing import *
# @lc code=start
class Solution_my:
    def get_permutation(self, sr:str):
        if len(sr) == 0:
            return [""]
        if len(sr) == 1:
            return [sr]
        res = []
        ban = []
        for i, s in enumerate(sr):
            if s in ban:
                continue
            ban.append(s)  # 重复字母
            cur_res = self.get_permutation(sr[:i]+sr[i+1:])
            for item in cur_res:
                item += s
                res.append(item)
        return res

    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        if len(strs) == 0:
            return []
        result = []
        hash_table = dict()
        for item in strs:
            if item in hash_table:
                i = hash_table[item]
                result[i].append(item)
            else:
                size = len(result)
                per_res = self.get_permutation(item)
                for p in per_res:
                    hash_table[p] = size  # 在 result 中的下标
                result.append([item])
        return result
            
class Solution:
    def groupAnagrams(self,strs):
        temp_dict={}
        for temp_str in strs:
            sort_str = self.HashMapFunc(temp_str)
            if sort_str in temp_dict:
                temp_dict[sort_str].append(temp_str)
            else:
                temp_dict[sort_str]=[temp_str]
        return list(temp_dict.values())


    def HashMapFunc(self, temp_str):
        return ''.join(sorted(list(temp_str)))    
# @lc code=end

if __name__ == "__main__":
    s = Solution()
    temp = s.get_permutation('eat')
    pass