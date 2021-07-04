// https://leetcode-cn.com/problems/chuan-di-xin-xi/

/*
基于邻接表的，DFS
*/

class Solution {
    int end;
    unordered_map<int, vector<int>>  adj_table;
    int DFS(int start, int k){
        // start -> end 长度为 k 的路径数
        if(start == end && k==0) return 1;
        if(k <= 0) return 0;

        int res = 0;
        // 遍历所有 start 的邻接节点
        for(int adj_num: adj_table[start]){
            res += DFS(adj_num, k-1);
        }
        return res;
    }
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        end = n-1;
        for(int i=0; i<n; i++){// 初始化
            adj_table[i] = {}; 
        }
        for(auto r: relation){// 构建邻接表
            adj_table[r[0]].emplace_back(r[1]); 
        }
        return DFS(0, k);
    }
};