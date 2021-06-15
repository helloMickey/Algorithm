// https://leetcode-cn.com/problems/numbers-with-repeated-digits/

// https://blog.csdn.net/Anxdada/article/details/88649496

typedef long long ll;
ll dp[20][20][2]; // dp[st][cur][state] 表示 从下标 st 到 cur 之间的数为 state状态（已满足，未满足）时，问题的结果值为多少！
ll shu[20]; // shu 记录数组中的每一位
ll vis[20]; // vis 记录当前递归中前面数字已经出现的次数
ll dfs(int st, int cur, int id, int state, int limit) {
	// st 起始位, cur 当前位, id 上一位填的数字, state 是否已经满足（前面的数已经满足出现多次了）, limit最高位限制
	++vis[id];
	if (cur < 1) {
		--vis[id];
		return state;
	}
	if (!limit && dp[st][cur][state] != -1) { // dp[st][cur][state] 已经记录过， dp 记录的一定是非限制状态下的
		--vis[id];
		return dp[st][cur][state];
	}

	int up = limit ? shu[cur] : 9;
	ll res = 0;

	for (int i = 0; i <= up; ++i) {
		if (st == cur && !i) // i 取 0，且所有前导为 0
			res += dfs(st - 1, cur - 1, id, state, limit && i == up);
		else if (state) // st 到 cur 之间 已满足
			res += dfs(st, cur - 1, i, state, limit && i == up);
		else res += dfs(st, cur - 1, i, bool(vis[i]), limit && i == up); // st 到 cur 之间 还未满足
	}
	if (!limit) dp[st][cur][state] = res;
	--vis[id];
	return res;
}
ll cal(ll x) {
	int k = 0;
	while (x) {
		shu[++k] = x % 10;
		x /= 10;
	}
	return dfs(k, k, 15, 0, 1); 
}
class Solution {
public:
	int numDupDigitsAtMostN(int N) {
		memset(dp, -1, sizeof(dp));
		return cal(N);
	}
};