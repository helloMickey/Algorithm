// https://leetcode-cn.com/problems/largest-rectangle-in-histogram/

/*
单调栈思路：
当右侧存在柱子比其小时，那么可以不用往后看了，栈顶元素作为高度的矩形肯定不会再往后扩了。
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(!heights.size()) return 0;
        stack<int> dec;
        int max_res = 0; int left_bound = 0;
        // 因为是单调递增栈，所有当 h[i] > 栈顶元素时，矩形的右边界就是 i 处。
        for(int i = 0; i < heights.size(); i++){
            while (!dec.empty() && heights[dec.top()] > heights[i]) {
				int j = dec.top();dec.pop();
                int gap = dec.empty() ? (i - left_bound) : (i - dec.top() - 1); // 根据左右边界，得到矩形的底边长
				max_res = max(max_res, heights[j] * gap);
				
			}
            if(heights[i] == 0) left_bound = i + 1; // 出现 0 高度，则相当于只看 0 之后的部分
            else dec.push(i);
        }

        int i = heights.size();
        while(!dec.empty()){ // 处理栈中剩余的元素
            int j = dec.top(); dec.pop();
            int gap = dec.empty() ? (i - left_bound) : (i - dec.top() - 1);
            max_res = max(max_res, heights[j] * gap);
        }
        return max_res;
    }
};