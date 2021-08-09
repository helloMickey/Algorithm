// https://leetcode-cn.com/problems/queue-reconstruction-by-height/

class Solution {
    struct compF{
        bool operator()(const vector<int>& a, const vector<int>& b){
            if(a[0] == b[0]) return a[1] < b[1]; // 对于相同身高 [5, 2] > [5, 3]
            return a[0] > b[0]; // 按身高从高到底排序；
        }
    };
public:
    static bool comp(const vector<int>& a, const vector<int>& b){
        if(a[0] == b[0]) return a[1] < b[1]; // 对于相同身高 [5, 2] > [5, 3]
        return a[0] > b[0]; // 按身高从高到底排序；
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 两种自定义比较过程的写法：函数指针、仿函数

        // sort(people.begin(), people.end(), comp);

        compF comp;
        sort(people.begin(), people.end(), comp);


        vector<vector<int> > res;
        for(auto p : people){
            // 插入排序
            res.insert(res.begin() + p[1], p);
        }
        return res;
    }
};