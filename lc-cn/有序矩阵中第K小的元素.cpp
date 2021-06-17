// https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/submissions/

// 也可以基于二分法实现， 见题解 https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/solution/you-xu-ju-zhen-zhong-di-kxiao-de-yuan-su-by-leetco/

class Solution { // 多路归并思想
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // 每行都是有序的，可以通过 归并排序 得到最终的有序序列
        // 由于题中只需要第 k 个元素，因此并不需要实际的进行数据存储，进行多路归并即可
        int M = matrix.size();
        if(M == 0) return 0;
        if(M == 1) return matrix[0][k-1];

        int N = matrix[0].size();

        vector<vector<int>::iterator> m_p;
        for(int i=0; i<M; i++) m_p.push_back(matrix[i].begin()); // N 路归并的头

        int c = 0;
        int res;
        while(c < k){
            int cur_min_val = INT_MAX;
            int cur_min_p_i = 0;
            for(int i=0; i<M; i++){ // 遍历 M 路
                auto p = m_p[i];
                if(p >= matrix[i].end()) // 该路已经遍历完了
                    continue; 
                if( *p < cur_min_val){ // 获取M路中的最小值
                    cur_min_val = *p;
                    cur_min_p_i = i; 
                }
            }
            
            m_p[cur_min_p_i]++; // 最小值对应路，指针向后移动一位
            c++;
            res = cur_min_val;

            // cout << cur_min_p_i << " " << res <<endl;
        }
        return res;
    }
};