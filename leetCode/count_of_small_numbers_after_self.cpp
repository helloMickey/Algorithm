#include<vector>
//#include<iterator>
using namespace std;
class Solution {
public:
	vector<int> countSmaller(vector<int>& nums) {
		for (vector<int>::iterator item = nums.begin(); item != nums.end(); item++)
		{
			int count = 0;
			for (vector<int>::iterator traverse = item + 1; traverse != nums.end(); traverse++)
			{
				if (*traverse < *item)
				{
					count++;
				}
			}
			*item = count;
		}
		return nums;
	}
};