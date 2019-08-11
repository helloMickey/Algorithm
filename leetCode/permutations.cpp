#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> result;
		//递归终止条件
		if (nums.size() == 1) {
			result.push_back(nums);
			return result;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			int cur = nums[i];
			vector<int> sub_nums(nums);//拷贝一份 nums
			sub_nums.erase(sub_nums.begin() + i);//除去其中的 cur
			
			//生成子序列的所有排列
			vector<vector<int>>sub_nums_pmt = permute(sub_nums);

			for (int j = 0; j < sub_nums_pmt.size(); j++)
			{
				//取出其中的一个排列
				vector<int> item = sub_nums_pmt[j];
				//在其头部插入 cur 构成以cur开头的一个排列
				item.insert(item.begin(), cur);

				result.push_back(item);//添加到返回值中
			}
		}

		return result;
	}
};
/*
int main() {
	Solution obj;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	obj.permute(nums);
}
*/
