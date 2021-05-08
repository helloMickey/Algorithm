// https://leetcode-cn.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        // 进行两次二分查找即可 log(m) + log(n)， 先确定在哪一行，再确定在那一列
        // 也可以将二维矩阵视作一个一维数组（本质上也是这样存储的），然后进行二分查找
        if(matrix.size() < 1){
            return false;
        }
        int M = matrix.size(), N = matrix[0].size();
        int head = 0, rear = M*N - 1;
        int mid;
        while (head <= rear)
        {
            /* code */
            mid = (head+rear)/2;
            int val = matrix[mid/N][mid%N];
            if (val == target)
            {
                return true;
            }else if(val < target){
                head = mid + 1; // !!!
            }else{
                rear = mid - 1;
            }
        }
        return false;
    }
};