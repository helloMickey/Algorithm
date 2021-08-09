// https://leetcode-cn.com/problems/sliding-window-maximum/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 单调队列，单调递减队列
        
        int n = nums.size();
        deque<int> q;
        for (int i = 0; i < k; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }

        vector<int> ans = {nums[q.front()]};
        for (int i = k; i < n; ++i) {
            // 弹出队列中小于 nums[i] 的值
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            
            // 弹出队列头部，不在窗口中的元素
            if (q.front() <= i - k) {
                q.pop_front();
            }
            
            // 当前窗口最大值
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }

    vector<int> maxSlidingWindow_2(vector<int>& nums, int k){
        //最大堆

        int n = nums.size();
        priority_queue<pair<int, int>> max_val;
        
        for(int i=0;i<k;i++) {
            max_val.emplace(nums[i], i);
        }

        vector<int> res = {max_val.top().first };

        for(int i=k; i<n; i++){
            cout << i << " ";
            max_val.emplace(nums[i], i);
            // 窗口右移，弹出不在窗口中的元素
            while(max_val.top().second < (i-k+1)){
                // 堆中的元素不在窗口中
                max_val.pop();
            }    
            // 获取当前窗口的最大值
            res.push_back(max_val.top().first);
        }
        return res;
    }
    
};