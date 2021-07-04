// https://leetcode-cn.com/problems/snakes-and-ladders/


class Solution { // 存在Bug，有测试用例通不过！！！！！
	int M, N;
	queue<int> cur_q; // 队列记录当前遍历者
	pair<int, int> num2idx(int num) { // 由标号转矩阵下标
		int m, n;
		int cevt = M * N - num;
		m = cevt / N;
		n = cevt % N;
		if ((m % 2) != 0) {
			n = N-1 - n; // 反转行
		}
		return std::make_pair(m, n);
	}
public:

	int snakesAndLadders(vector<vector<int>>& board) {
		// 广度优先遍历，找到最短路径。
		M = board.size(); N = board[0].size();
		vector<int> visit(M*N + 1, -1);
		cur_q.push(1); visit[1] = 0; // 起始
        
		while (!cur_q.empty()) {
			int cur_num = cur_q.front(); cur_q.pop();
			// 从当前位置开始
            auto cur_idxs = num2idx(cur_num);
            int cur_flag = board[cur_idxs.first][cur_idxs.second];
            if(cur_flag != -1){// 当前位置本身存在梯子
                if (cur_flag == M * N) return visit[cur_num] + 1; // 梯子的结束处为终点
				visit[cur_flag] = visit[cur_num]; // 梯子起始位置 
				cur_q.push(cur_flag);
                continue;
            }
			// cout << cur_num << endl;
			for (int s = 1; s <= 6; s++) {
				int next_num = cur_num + s;
				if (next_num < 1 || next_num > M*N) continue; //不合法

				if (next_num == M * N) return visit[cur_num] + 1; //最先到达终点, 返回所需步数
				if (visit[next_num] != -1) continue; // 已经遍历过

				// cout << next_num << " ";
				auto idxs = num2idx(next_num);
				int m = idxs.first, n = idxs.second;

				if (board[m][n] != -1) {
					if (board[m][n] == M * N) return visit[cur_num] + 1; // 梯子的结束处为终点
					visit[next_num] = visit[cur_num]; // 梯子起始位置 
					next_num = board[m][n]; // 梯子或蛇的终止位置
				}

				if (visit[next_num] != -1) continue; // 梯子或蛇的终止位置有可能已经遍历过
				visit[next_num] = visit[cur_num] + 1;
				cur_q.push(next_num);
			}

			// cout << endl;
		}
		return 0;
	}

};

class Solution_Answer {

    /*
    作者：LeetCode-Solution
    链接：https://leetcode-cn.com/problems/snakes-and-ladders/solution/she-ti-qi-by-leetcode-solution-w0vl/
    来源：力扣（LeetCode）
    著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    */
    pair<int, int> id2rc(int id, int n) {
        int r = (id - 1) / n, c = (id - 1) % n;
        if (r % 2 == 1) {
            c = n - 1 - c;
        }
        return {n - 1 - r, c};
    }

public:
    int snakesAndLadders(vector<vector<int>> &board) {
        int n = board.size();
        vector<int> vis(n * n + 1);
        queue<pair<int, int>> q;
        q.emplace(1, 0);
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            for (int i = 1; i <= 6; ++i) {
                int nxt = p.first + i;
                if (nxt > n * n) { // 超出边界
                    break;
                }
                auto rc = id2rc(nxt, n); // 得到下一步的行列
                if (board[rc.first][rc.second] > 0) { // 存在蛇或梯子
                    nxt = board[rc.first][rc.second];
                }
                if (nxt == n * n) { // 到达终点
                    return p.second + 1;
                }
                if (!vis[nxt]) {
                    vis[nxt] = true;
                    q.emplace(nxt, p.second + 1); // 扩展新状态
                }
            }
        }
        return -1;
    }
};