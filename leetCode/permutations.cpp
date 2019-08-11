#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> result;
		//�ݹ���ֹ����
		if (nums.size() == 1) {
			result.push_back(nums);
			return result;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			int cur = nums[i];
			vector<int> sub_nums(nums);//����һ�� nums
			sub_nums.erase(sub_nums.begin() + i);//��ȥ���е� cur
			
			//���������е���������
			vector<vector<int>>sub_nums_pmt = permute(sub_nums);

			for (int j = 0; j < sub_nums_pmt.size(); j++)
			{
				//ȡ�����е�һ������
				vector<int> item = sub_nums_pmt[j];
				//����ͷ������ cur ������cur��ͷ��һ������
				item.insert(item.begin(), cur);

				result.push_back(item);//��ӵ�����ֵ��
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
