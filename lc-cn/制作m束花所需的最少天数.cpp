// https://leetcode-cn.com/problems/minimum-number-of-days-to-make-m-bouquets/

class Solution {
public:
    int mm, kk;
    bool maked(const vector<int>& bloomDay, int d){
        // O(n) 的时间判断是否能满足制作需求
        
        // 计算能制作的花束
        int count = 0;
        int temp_m = 0;
        for(int needd: bloomDay){
            if(needd <= d){
                count++;
            }else{
                count = 0; //不连续
            }
            if(count == kk){ //连续k多花
                temp_m++; //可以制作一个花束
                count = 0;
            }
        }
        return temp_m >= mm;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m*k > bloomDay.size()){
            return -1;
        }
        mm = m; kk = k;
        int maxd = *std::max_element(bloomDay.begin(), bloomDay.end());
        int mind = 1;
        int resd = maxd, curd;
        while(mind <= maxd){
            curd = (maxd + mind)/2;
            if(maked(bloomDay, curd)){
                resd = curd; // 记录结果中最小的天数
                maxd = curd - 1; // 尝试更少天数
            }else{
                // 不可以制作
                mind = curd + 1; // 尝试更多天数
            }
        }
        return resd;
    }
};