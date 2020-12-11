#
# @lc app=leetcode.cn id=36 lang=python3
#
# [36] 有效的数独
#
from typing import *
# @lc code=start
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        cols_set = [ ]
        block_set = [ ]
        for i in range(9):
            cols_set.append(set())
            block_set.append(set())
        # 按行遍历
        for i in range(9):
            row_set = set()
            for j in range(9):
                s = board[i][j]
                if s != '.':
                    if (s in row_set) or (s in cols_set[j]) or (s in block_set[int(i/3)*3 + int(j/3)]):
                        return False
                    else:
                        row_set.add(s)
                        cols_set[j].add(s)
                        block_set[int(i/3)*3 + int(j/3)].add(s)
            pass
        pass
        return True
                
                
# @lc code=end
if __name__ == "__main__":
    a = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
    s = Solution()
    s.isValidSudoku(a)