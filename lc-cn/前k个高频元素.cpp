// https://leetcode-cn.com/problems/top-k-frequent-elements/submissions/

class Solution {
    // 先统计每个数字出现的频次
    // 以频次为大小，挑选前 K 个 => 问题转化为 Top-K 
public:
    static bool cmp(pair<int, int>& m, pair<int, int>& n) {
        // 自定义compare
        return m.second > n.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> occurrences;
        for (auto& v : nums) {
            occurrences[v]++;
        }

        // pair 的第一个元素代表数组的值，第二个元素代表了该值出现的次数
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp); // 默认是大根堆
        
        for (auto& [num, count] : occurrences) {
            if (q.size() == k) {
                if (q.top().second < count) {
                    q.pop();
                    q.emplace(num, count);
                }
            } else {
                q.emplace(num, count);
            }
        }
        
        vector<int> ret;
        while (!q.empty()) {
            ret.emplace_back(q.top().first);
            q.pop();
        }
        return ret;
    }
};
