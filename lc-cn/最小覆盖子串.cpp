// https://leetcode-cn.com/problems/minimum-window-substring/

// 也是经典的滑动窗口；

class Solution {
public:
    string minWindow(string s, string t){
        unordered_map<char, int> ch_c; // 统计当前窗口内，还需要的字符及其数目
        int mch_c = 0; // 记录总共需要的字符数
        for(char c : t){
            if(ch_c.find(c) != ch_c.end()) ch_c[c] += 1;
            else ch_c[c] = 1;
            mch_c++;
        }
        
        int res = INT_MAX;
        pair<int, int> trv = {0, -1};
        int head=0, rear = -1;

        while(rear <= (int)s.size()){ // 这里判断 <= ，而不是 <            
            
            if(mch_c > 0){ 
                //当前窗口不满足，则扩充
                rear++; 
                if(rear > (int)s.size()) break;

                // 扩张后~
                char cur = s[rear];
                if(ch_c.find(cur) != ch_c.end()) {
                    if(ch_c[cur] > 0) mch_c--;
                    ch_c[cur]--;
                }
            } 
            else{ 
                // 当前窗口满足，尝试对窗口进行缩小
                if(rear - head + 1 < res) {
                    res = rear-head+1;
                    trv.first = head;
                    trv.second = rear;
                }
                // 要看缩小后对当前窗口造成的影响
                if(ch_c.find(s[head]) != ch_c.end()) {
                    ch_c[s[head]] += 1; 
                    if(ch_c[s[head]] > 0) mch_c += 1;
                } 
                
                head++; // 尝试缩小窗口
            }
            // cout << head << " " << rear << endl; 
        }
        return s.substr(trv.first, trv.second - trv.first + 1);
    }
};