#include<vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> result;
	vector<vector<int>> permute(vector<int>& nums) {
		permute(nums, nums.size());
	}
	void permute(vector<int>& nums, int count) {
		if (nums.size() < 1)
			return;
		for (int i = 0; i < count; i++)
		{
			result[i];
		}
	}
};