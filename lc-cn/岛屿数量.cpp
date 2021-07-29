// https://leetcode-cn.com/problems/number-of-islands/

class Solution {
    vector<vector<bool>> visit;
    int m, n;
    void _dfs(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || i>= m || j < 0 || j >= n) return;
        if(visit[i][j]) return;
        if(grid[i][j] == '0') return;

        visit[i][j] = true;
        // 上下左右探索
        _dfs(grid, i-1, j);
        _dfs(grid, i+1, j);
        _dfs(grid, i, j-1);
        _dfs(grid, i, j+1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        visit = vector<vector<bool>>(m, vector<bool>(n, false));
        // 求连通域个数
        int res = 0;
        for(int i=0; i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1' && !visit[i][j]){
                    res++;
                    _dfs(grid, i, j);
                }
            }
        }
        return res;
    }
};