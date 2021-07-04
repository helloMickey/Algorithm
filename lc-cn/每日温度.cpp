// https://leetcode-cn.com/problems/daily-temperatures/

class Solution {
public:
    // 单调栈.... O(2n)
    vector<int> dailyTemperatures(vector<int> temperatures){
        vector<int> res(temperatures.size(), 0);
        stack<int> idx_stack; // 递减栈
        
        for(int i = 0; i < temperatures.size(); i++){            
            while(!idx_stack.empty() && 
            temperatures[idx_stack.top()] < temperatures[i])
            {
                    int cur_idx = idx_stack.top(); idx_stack.pop();
                    res[cur_idx] = i - cur_idx; // 记录第一个比 cur_idx 温度高的所隔天数
            }
            idx_stack.push(i);            
        }
        return res;
    }
    // 暴力算法 O(2n)
    /*
    可以进行优化 -> 由于温度都是在 [30, 100] 范围内的整数，
    所以可以通过数组记录每个温度值第一次出现的下标 count
    对于每一天的温度，从count中的temp[i] + 1 下标开始遍历 count，找到其中大于i的最小值（里i最近的一天）
    复杂度 O(kn)
    */
    vector<int> dailyTemperatures_1(vector<int>& temperatures) {
        int days = temperatures.size();
        vector<int> res(days, 0);
        for(int i = days-2; i > -1; i--){
            int j = i + 1;
            while((j < days) && temperatures[j] <= temperatures[i]){// 找大于 temp[i] 的那一天
                if(res[j] == 0) break; // 之后的都不会更大了
                j += res[j]; // 找下一个比 temp[j] 大的值 

            }
            if(j < days) res[i] = temperatures[j] > temperatures[i] ? (j-i) : 0;
        }
        return res;
    }
};