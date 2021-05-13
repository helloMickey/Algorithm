// https://leetcode-cn.com/problems/xor-queries-of-a-subarray/solution/zi-shu-zu-yi-huo-cha-xun-by-leetcode-solution/

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        /***
         * 异或操作具有的性质：
         *  0 ^ x = x
         *  x ^ x = 0
         * **/
        /***
         * Q(left,right)
            =arr[left]⊕…⊕arr[right]
            =(arr[0]⊕…⊕arr[left−1])⊕(arr[0]⊕…⊕arr[left−1])⊕(arr[left]⊕…⊕arr[right])
            =(arr[0]⊕…⊕arr[left−1])⊕(arr[0]⊕…⊕arr[right])
            =xors[left]⊕xors[right+1]
         * **/
        for (int i = 1; i < arr.size(); i++)
        {
            arr[i] = arr[i] ^ arr[i-1]; // 连续异或操作结果的保存
        }
        vector<int> res;
        for(const vector<int>& q : queries){
            if(q[0] == 0){
                res.push_back(arr[q[1]]);
            }
            else{
                res.push_back(arr[q[0] - 1] ^ arr[q[1]]);
            }
        }
        return res;
    }
};