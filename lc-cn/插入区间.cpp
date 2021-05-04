// https://leetcode-cn.com/problems/insert-interval/

/**
在给定的区间集合 互不重叠的前提下，当我们需要插入一个新的区间 S 时，我们只需要找出所有与区间 S 重叠的区间集合 Xn ；将 Xn 中的所有区间连带上区间 S 合并成一个大区间；
**/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        auto p = intervals.begin();
        int l_b = newInterval[0], r_b = newInterval[1];
        bool has_union = false;

        for(; p != intervals.end(); p++){
            // 遍历
            auto cur_iter = *p;
            // 判断当前区间是否与 newInterval 存在交集
            if(newInterval[0] > cur_iter[1] || newInterval[1] < cur_iter[0]){
                // 当前没有交集
                if(has_union || (p!=intervals.end() && (r_b < (*p)[0]))){ // 之前有交集 或 newInterval 位于当前区间左侧了
                    // 先将并集push到最终结果之中
                    vector<int> u = {l_b, r_b};
                   res.push_back(u); 
                   // 后面的cur_iter 肯定不会再相交了
                   while(p != intervals.end()){
                       res.push_back(*p);
                       p++;
                   }
                   return res;
                }
                res.push_back(cur_iter);
            }else{
                //存在交集, 当前并集合的左右边界
                l_b = cur_iter[0] < l_b ? cur_iter[0] : l_b;
                r_b = cur_iter[1] > r_b ? cur_iter[1] : r_b;
                has_union = true;
            }
        }
        //遍历到结束 没有return，说明 newInterval 没有和其他 cur_iter 存在交集，位于最右端
        vector<int> u = {l_b, r_b}; // 位于最左端
        res.push_back(u);
        return res;
    }
};