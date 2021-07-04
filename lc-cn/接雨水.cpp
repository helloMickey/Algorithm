// https://leetcode-cn.com/problems/trapping-rain-water/

/*
暴力算法：
直接对于每一个柱子，找到右侧第一个可以与当前柱围成凹槽的柱子，计算凹槽中的容量
复杂度：O(n^2)

改进：单调（递减）栈
这样不用每个柱子，都去找右侧比其高的柱子。而是，当出现高的柱子才去计算形成的凹槽能够存储的容量
*/

class Solution {
public:
	int trap(vector<int>& height) {
		stack<int> des; // 递减栈
		int res = 0;

		for (int i = 0; i < height.size(); i++) {
			int cur_h = height[i];
			
            if (!des.empty() && cur_h > height[des.top()]) { // 当前，大于栈顶              
				int mid_hi, left_bi = des.top(); des.pop();

				while (height[left_bi] < cur_h && !des.empty()) {
					mid_hi = left_bi;
					left_bi = des.top(); des.pop();
					// 当前凹槽可以存储的雨水量
					res += (min(height[left_bi], cur_h) - height[mid_hi]) * (i - left_bi - 1);
				}
                if (height[left_bi] > cur_h) des.push(left_bi); // 如果左边界大于当前 cur_h， 则需要保留
			}
			des.push(i); // cur_h 入栈
		}
		return res;
	}
};