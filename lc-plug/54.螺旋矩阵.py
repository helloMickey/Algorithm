#
# @lc app=leetcode.cn id=54 lang=python3
#
# [54] 螺旋矩阵
#
from typing import *
# @lc code=start
class Solution:
    def spiralOrder_old(self, matrix: List[List[int]]) -> List[int]:
        res = []
        m = len(matrix)
        if m < 1:
            return res
        n = len(matrix[0])
        r = 0
        c = 0
        max_r, min_r = m-1, 0
        max_c, min_c = n-1, 0
        i = 0
        while i < m*n:
            if c < max_c and r == min_r:
                item = matrix[r][c]
                res.append(item)
                c += 1
                i += 1
            elif c == max_c and r == min_r:
                item = matrix[r][c]
                res.append(item)
                
                r += 1
                i += 1
            elif c == max_c and r < max_r:
                item = matrix[r][c]
                res.append(item)
                r += 1
                i += 1
            elif c == max_c and r == max_r:
                item = matrix[r][c]
                res.append(item)

                min_r += 1
                
                c -= 1
                i += 1
            elif c > min_c and r == max_r:
                item = matrix[r][c]
                res.append(item)
                c -= 1
                i += 1
            elif c == min_c and r == max_r:
                item = matrix[r][c]
                res.append(item)

                max_c -= 1
                
                r -= 1
                i += 1
            elif c == min_c and r > min_r:
                item = matrix[r][c]
                res.append(item)
                r -= 1
                i += 1
            elif c == min_c and r == min_r:
                item = matrix[r][c]
                res.append(item)

                max_r -= 1
                # min_c += 1
                c += 1
                i += 1

        return res

    def spiralOrder_oldV2(self, matrix: List[List[int]]) -> List[int]:
        res = []
        m = len(matrix)
        if m < 1:
            return res
        n = len(matrix[0])
        r = 0
        c = -1
        max_r, min_r = m-1, 0
        max_c, min_c = n-1, 0
        i = 0
        flag = 'right'
        while i < m*n:
            if flag == 'right':
                c += 1
            elif flag == 'down':
                r += 1
            elif flag == 'left':
                c -= 1
            elif flag == 'up':
                r -= 1
            
            item = matrix[r][c]
            res.append(item)
            i += 1
            

            # 转向
            if r==min_r and c<=min_c:
                min_r += 1
                flag = 'right'
            elif r <= min_r and c == max_c:
                max_c -= 1
                flag = 'down'
            elif r == max_r and c >= max_c:
                max_r -= 1
                flag = 'left'
            elif r >= max_r and c == min_c:
                min_c += 1
                flag = 'up'     
        return res

    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m = len(matrix)
        n = len(matrix[0])
        res = []
        l, r, t, b = 0, n-1, 0, m-1
        i = 0
        while True:
            for j in range(l, r+1):  # left -> right
                res.append(matrix[t][j])
                i += 1
                pass
            t += 1
            if t > b:
                break

            for j in range(t, b+1):  # top -> bottom
                res.append(matrix[j][r])
                i += 1
                pass
            r -= 1
            if r < l:
                break

            for j in range(r, l-1, -1):  # right -> left
                res.append(matrix[b][j])
                i += 1
                pass
            b -= 1
            if b < t:
                break

            for j in range(b, t-1, -1):  # dottom -> top
                res.append(matrix[j][l])
                i += 1
                pass
            l += 1
            if l > r:
                break
            
        return res
# @lc code=end
if __name__ == "__main__":
    S = Solution()
    S.spiralOrder([
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
])
