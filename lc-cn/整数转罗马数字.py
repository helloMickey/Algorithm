"""
https://leetcode-cn.com/problems/integer-to-roman/
"""

class Solution:
    def intToRoman(self, num: int) -> str:
        vocab = {
            1:"I",
            5:"V",
            10:"X",
            50:"L",
            100:"C",
            500:"D",
            1000:"M",
            4:"IV",
            9:"IX",
            40:"XL",
            90:"XC",
            400:"CD",
            900:"CM"
        }
        # 字典按照 key 从大到小 进行排序
        sorted_keys = sorted(vocab.keys(), reverse=True)
        r = ''
        for n in sorted_keys:
            if int(num/n) > 0: 
                c = vocab[n] * int(num / n)
                num = num%n  # 取余 
                r += c
        return r   

if __name__ == "__main__":
    S = Solution()
    S.intToRoman(4)