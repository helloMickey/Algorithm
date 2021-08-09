// https://leetcode-cn.com/problems/maximal-square/

/*
还有更优的动态规划解法：
用 dp(i,j) 表示以 (i, j)为右下角，且只包含 1 的正方形的边长最大值。
dp(i,j) = min(dp(i−1,j), dp(i−1,j−1), dp(i,j−1)) + 1

见：https://leetcode-cn.com/problems/maximal-square/solution/zui-da-zheng-fang-xing-by-leetcode-solution/
*/

class Solution {
	struct hash_func { // pair 自定义的 hash 函数
		size_t operator()(const pair<int, int> & a) const {
			string temp = to_string(a.first) + "," + to_string(a.second);
			std::hash<std::string> str_hash;
			return str_hash(temp);
		}
	};
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		/*
		暴力：尝试每一种大小规格的正方形，遍历每一个位置作为可能的正方形左上角起点

		优化：对于一个位置 m[i][j]，其能够作为 n*n 正方形的左上角的条件是：
				m[i][j]、m[i+1][j] 、m[i][j+1]、 m[i+1][j+1] 分别能够作为左上角构成 (n-1)*(n-1) 的矩阵
		*/
		int M = matrix.size(), N = matrix[0].size();

		 unordered_set<std::pair<int,int>, hash_func> m_set;

		int res = 0;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (matrix[i][j] == '1') {
					m_set.insert(std::make_pair(i, j)); // 能够构成 1*1 的正方形
				}
			}
		}
		while (!m_set.empty()) {
			res += 1;

			auto temp_set = m_set;
			m_set.clear();
			for (auto idxs : temp_set) {
				int i = idxs.first, j = idxs.second;

				if (temp_set.count(make_pair(i + 1, j))
					&& temp_set.count(make_pair(i, j + 1))
					&& temp_set.count(make_pair(i + 1, j + 1))) {
					m_set.emplace(i, j);
				}
			}
		}

		return res * res;
	}
};