// https://leetcode-cn.com/problems/brick-wall/

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        // 遍历每行，记录每个间隙下，有多少砖块发生了遮挡 (高度 - 没有遮挡的)，
        int height = wall.size();
        if(height < 1){return 0;}

        // int gap_idx_nums = std::accumulate(wall[0].begin(), wall[0].end(), 0) - 1; // 缝隙数
        //if(gap_idx_nums <= 0){return height;} //[[1],[1],[1]] 每层只有一块砖，没有缝隙
        // vector<int> counter(gap_idx_nums, 0); // [[100000000,100000000],[100000000,100000000]]
        // 不要用vector以单位1来进行缝隙记录
        unordered_map<int, int> counter;
        
        for(int i=0; i < wall.size(); i++){
            int gap_idx = -1;
            for(int j=0; j < wall[i].size() - 1;j++){//最后一块砖不计
                gap_idx += wall[i][j];
                // counter[gap_idx]++;
                auto f_p = counter.find(gap_idx);
                if(f_p != counter.end()){
                    f_p->second += 1;
                }else{
                    counter.insert(make_pair(gap_idx, 1));
                }
            }
        }
        // return height - *max_element(counter.begin(), counter.end());
        
        // return height - max_element(counter.begin(), counter.end(), [](auto a, auto b) -> bool { return a.second < b.second;}) -> second;

        int res = height;
        for(auto pr:counter){
            res = std::min(res, height-pr.second);
        }
        return res;
    }
};