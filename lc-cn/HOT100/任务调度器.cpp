// https://leetcode-cn.com/problems/task-scheduler/
/*
思路：模拟调度的过程，获得最总的结果。对于本题目而言也是一个贪心计算的过程

本题另外一个有意思的构造解法：https://leetcode-cn.com/problems/task-scheduler/solution/ren-wu-diao-du-qi-by-leetcode-solution-ur9w/
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n == 0) return tasks.size();
        // int char_c[26];
        // memset(char_c, 0, sizeof(char_c));

        vector<pair<char, int>> char_c;
        for(int i=0; i<26;i++) char_c.push_back(make_pair('A'+ i, 0));
        // 记录每个字符出现的次数
        for(char t : tasks) char_c[t - 'A'].second += 1;
        // 按照出现次数排序
        sort(char_c.begin(), char_c.end(), [](pair<char, int> a, pair<char, int> b)->bool { return a.second > b.second;}); // 按照频次降序排序；

        int s = tasks.size();
        int res = 0;
        
        while(s){
            int c = n+1; int i = 0;
            for(; i < c; i++){
                if(i < 26 && char_c[i].second != 0) { 
                    char_c[i].second--;
                    s--; // 进行一次任务的调度
                    res++;
                }
                else res++; // 没有其他任务可以插入，要执行等待一次
                
                if(!s) break; // 调度完成
            }
            // 有些字符出现次数可能已经减为0，因为重排下
            sort(char_c.begin(), char_c.end(), [](pair<char, int> a, pair<char, int> b)->bool { return a.second > b.second;}); 
        }
        return res;
    }
};