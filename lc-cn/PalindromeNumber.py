class Solution:
    def isPalindrome(self, x: int) -> bool:
        s_1 = str(x)
        s_2 = str(x)[::-1]
        if s_2 == s_1:
            return True
        else:
            return False