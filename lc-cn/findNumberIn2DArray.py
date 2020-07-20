class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        r, c = len(matrix), len(matrix[0]) if len(matrix) > 0 else 0
        i = 0
        j = c-1
        while i<r and j>=0:
            if matrix[i][j] != target:
                if matrix[i][j] < target:
                    i += 1
                else:
                    j -= 1

            else:
                return True
        return False
