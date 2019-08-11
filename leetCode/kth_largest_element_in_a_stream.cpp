#include<vector>
#include<algorithm>
using namespace std;

class KthLargest {
	int k;
	vector<int> k_max_data;
	int cur_min;
public:
	KthLargest(int k, vector<int> nums) {
		this->k = k;
		if (nums.size() >= k)
		{
			for (int i = 0; i < k-1; i++)
				k_max_data.push_back(nums[i]);
			for (int i = k - 1; i < nums.size(); i++)
				add(nums[i]);
		}
		else
		{
			for (int i = 0; i < nums.size(); i++)
				k_max_data.push_back(nums[i]);
		}
	}

	int add(int val) {
		if (k_max_data.size() == k) {
			if (val <= cur_min)
				return k_max_data[0];
			else
			{
				//for (int i = k-1; i >= 0; i++)
				//	if (val >= k_max_data[i]) {
				//		k_max_data.insert(k_max_data.begin() + i + 1, val);//��val������ʵ�λ��
				//		break;
				//	}
				k_max_data.push_back(val);
				sort(k_max_data.begin(), k_max_data.end());
				k_max_data.erase(k_max_data.begin());
				cur_min = k_max_data[0];
				return cur_min;
			}
		}
		if (k_max_data.size() == (k-1)) {
			k_max_data.push_back(val);
			//��stream���״ε���k��Ԫ��ʱ
			sort(k_max_data.begin(), k_max_data.end());//��k��Ԫ�ش�С��������
			cur_min = k_max_data[0];
			return cur_min;
		}
	}
};