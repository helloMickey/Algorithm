// https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/

// 回溯

class Solution {
public:
	string word;
	int M, N;
	vector<vector<char>> board;
	vector<vector<bool> > trved;
	bool _dfs(int m, int n, int d) {
		// if(d >= word.size()) return false;
		if (m >= M || m < 0 || n >= N || n < 0 || trved[m][n]) return false;

		if (board[m][n] != word[d]) return false;
		
		if (d == (word.size() - 1)) return true; // 完整匹配，遍历结束
        trved[m][n] = true; // 继续深入递归

		// 上下左右遍历
        bool find = _dfs(m - 1, n, d + 1) || _dfs(m + 1, n, d + 1) || _dfs(m, n - 1, d + 1) || _dfs(m, n + 1, d + 1);
        if(find) return true;
		
        // 上下左右都不行，回溯
		trved[m][n] = false;
		return false;
	}
	bool exist(vector<vector<char>>& board, string word) {
		int m = board.size(), n = board[0].size();
		trved = vector<vector<bool> >(m, vector<bool>(n, false));
		this->word = word;
		this->M = m, this->N = n;
		this->board = board;
		// DFS 
		for (int i = 0; i < m; i++) { // 尝试所有的入口
			for (int j = 0; j < n; j++) {
				if (_dfs(i, j, 0)) return true;
			}
		}
		return false;
	}
};