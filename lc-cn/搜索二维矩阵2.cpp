// https://leetcode-cn.com/problems/search-a-2d-matrix-ii/

// 该题的解法有好几种，最佳的还是方法四：
//https://leetcode-cn.com/problems/search-a-2d-matrix-ii/solution/sou-suo-er-wei-ju-zhen-ii-by-leetcode-2/

/*
从矩阵左下角开始，m[i][j] > target 则上移动；< target 则右移动；直到找到目标值
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // start our "pointer" in the bottom-left
        int row = matrix.size()-1;
        int col = 0;

        while (row >= 0 && col < matrix[0].size()) {
            if (matrix[row][col] > target) {
                row--;
            } else if (matrix[row][col] < target) {
                col++;
            } else { // found it
                return true;
            }
        }

        return false;
    }
};