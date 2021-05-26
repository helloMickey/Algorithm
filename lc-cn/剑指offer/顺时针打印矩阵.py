# https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/

# 与 螺旋矩阵 题目相同
class Solution:
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