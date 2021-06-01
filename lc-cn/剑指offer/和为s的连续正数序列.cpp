// https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/
/*
滑动窗口法
*/

class Solution {
public:
	int sum_val(int l, int r) { // 获取区间的连续和
		int res = 0;
		while (l <= r) {
			res += l;
			l++;
		}
		return res;
	}
	vector<int> gap_val(int l, int r) {// 返回该区间数值    
		vector<int> res;
		while (l <= r) {
			res.push_back(l);
			l++;
		}
		return res;
	}
	vector<vector<int>> findContinuousSequence(int target) {
		int l = target / 2, r = l + 1;
		vector<vector<int> > res;
		while (l > 0 && r < target) {
			int sum = sum_val(l, r);
			if (sum == target) {
				res.push_back(gap_val(l, r));
			}
			else if (sum < target) {//右滑
				do {
					sum = sum_val(++l, ++r);
				} while (sum < target && r < target);
				if (sum == target) res.push_back(gap_val(l, r));
			}
			else { // 左滑
				do {
					sum = sum_val(--l, --r);
				} while (sum > target && l > 0);
				if (sum == target) res.push_back(gap_val(l, r));
			}
			// 窗口调大
			l--;
		}
		std::reverse(res.begin(), res.end());
        return res;
	}
};