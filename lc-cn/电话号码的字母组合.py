from typing import *

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        s_len = len(digits)
        if s_len == 0:
            return [] 
        keyboard = {
            "2":['a', 'b', 'c'],
            "3":['d', 'e', 'f'],
            "4":['g', 'h', 'i'],
            "5":['j', 'k', 'l'],
            "6":['m', 'n', 'o'],
            "7":['p', 'q', 'r', 's'],
            "8":['t', 'u', 'v'],
            "9":['w', 'x', 'y', 'z'],
        }
        result = ['']
        for d in digits:
            prev_r = result
            result = []
            for alpt in keyboard[d]:
                for r in prev_r:
                    result.append(r + alpt)
            prev_r.clear()
        return result

if __name__ == "__main__":
    s = Solution()
    s.letterCombinations("23")
    pass