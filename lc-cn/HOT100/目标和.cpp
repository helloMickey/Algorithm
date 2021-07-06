// https://leetcode-cn.com/problems/target-sum/

class Solution { // dfs 搜索
	int res = 0;
	void dfs(vector<int>& nums, int i, int cur_target) {		
		if (i == nums.size()) {// 刚好遍历完整个数组
			if (cur_target == 0) {
				res++;
			}
			return;
		}
		dfs(nums, i + 1, cur_target - nums[i]); // + nums[i]
		dfs(nums, i + 1, cur_target + nums[i]); // - nums[i]
	}
public:
	int findTargetSumWays(vector<int>& nums, int target) {
		dfs(nums, 0, target);
		return res;
	}
};