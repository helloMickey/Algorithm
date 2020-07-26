"""
https://leetcode-cn.com/explore/interview/card/top-interview-questions-medium/29/array-and-strings/77/
"""
from typing import *
from collections import defaultdict

class StrGroup(str):
    def __eq__(self, s:object)->bool:
        if len(s) != len(self):
            return False
        for i in self:
            if i not in s:
                return False
        return True
    def __hash__(self)->bool:
        r = 0
        for i in self:
            r += ord(i)
        return r
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        counter = defaultdict(list)
        for s in strs:
            counter[StrGroup(s)].append(s)
        pass
        result = [item[1] for item in counter.items()]
        return result

if __name__ == "__main__":
    s = Solution()
    print(s.groupAnagrams( ["eat", "tea", "tan", "ate", "nat", "bat"]))
