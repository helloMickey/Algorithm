// https://leetcode-cn.com/problems/min-cost-to-connect-all-points/

// 最小生成树  
// kruscal 中涉及到并查集

struct info_node{
        int edge_len; // 边长、边的两个端点
        int p1_id;
        int p2_id;
        info_node(int e_l, int p1, int p2):edge_len(e_l), p1_id(p1), p2_id(p2){}

        // friend bool operator< (const info_node& a, const info_node& b){ // 记得声明为 friend 类型
        //     return a.edge_len > b.edge_len; // 最小堆。
        // }
        bool operator<(const info_node& a) const{
            return edge_len > a.edge_len;
        }
};

class union_find_set{
    vector<int> nums;
    int _s;
public:
    union_find_set(int size){
        _s = size;
        nums = vector<int>(size, -1); // 存储的数为正整数
    }
    bool find(int a, int b){
        int root_a = a, root_b = b;
        while(nums[root_a] != -1) root_a = nums[root_a];
        while(nums[root_b] != -1) root_b = nums[root_b];

        return root_a == root_b;
    }
    void unionset(int a, int b){
        // 没有优化的并查集
        int root_a = a, root_b = b;
        while(nums[root_a] != -1) root_a = nums[root_a];
        while(nums[root_b] != -1) root_b = nums[root_b];
        if(root_a == root_b) return;
        nums[root_a] = root_b; // 归入同一个root中
    }
};

class Solution {    
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // 最小生成树，基于边计算的算法        
        union_find_set uf_set(points.size()); // 并查集
        priority_queue<info_node> edge; // 默认是最大堆，自定义比较函数 
        
        for(int i=0; i < points.size(); i++){
            for(int j=i+1; j < points.size(); j++){ // 计算所有两点之间的距离
                int e_len = std::abs(points[i][0] - points[j][0]) + std::abs(points[i][1] - points[j][1]);
                info_node cur_info(e_len, i, j);
                edge.push(cur_info); // 压入最小堆
            }
        }

        int res = 0;
        while(!edge.empty()){
            auto info = edge.top(); edge.pop();

            if(uf_set.find(info.p1_id, info.p2_id)){// 边的两个端点在一个图中
                continue;
            }

            res += info.edge_len;

            uf_set.unionset(info.p1_id, info.p2_id);            
        }
        return res;
    }

    int minCostConnectPoints_Error(vector<vector<int>>& points) {
        // 最小生成树，基于边计算的算法
        set<int> visit_p; // 这里犯错了，kruscal 算法要用并查集来判断一个边是否可选。        
        priority_queue<info_node> edge; // 默认是最大堆，自定义比较函数 
        
        for(int i=0; i < points.size(); i++){
            for(int j=i+1; j < points.size(); j++){ // 计算所有两点之间的距离
                int e_len = std::abs(points[i][0] - points[j][0]) + std::abs(points[i][1] - points[j][1]);
                info_node cur_info(e_len, i, j);
                edge.push(cur_info); // 压入最小堆
            }
        }

        int res = 0;
        while(!edge.empty()){
            auto info = edge.top(); edge.pop();

            if(visit_p.find(info.p1_id)!=visit_p.end() && visit_p.find(info.p2_id) != visit_p.end()){
                // 边的两个端点都存在
                continue;
            }

            res += info.edge_len;

            if(visit_p.find(info.p1_id) == visit_p.end()){
                visit_p.insert(info.p1_id);
            }
            if(visit_p.find(info.p2_id) == visit_p.end()){
                visit_p.insert(info.p2_id);
            }
        }
        return res;
    }
};