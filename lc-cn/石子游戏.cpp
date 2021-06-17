// https://leetcode-cn.com/problems/stone-game/comments/
// 预测赢家中 没有对可去个数进行约定，石子游戏中可取个数限定为偶数


// 当然，采用和预测赢家同样的 dp 思路，可以得到正确判断结果
// 但实际上，先手必赢

class Solution { // DP
public:
    bool stoneGame(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int> > dp(len, vector(len, 0));
        
        for(int i=0; i<len; i++) dp[i][i] = nums[i];
        dp[0][0] = nums[0];
        
        for (int j = 1; j < len; j++)
        {
            /* code */
            for (int i = j-1; i >= 0; i--)
            {
                dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
            }           
        }
        return dp[0][len-1] >= 0; // 当前玩家与另一个玩家的分数之差 >= 0
    }
};

class Solution_Error { // 最开始的贪心策略是错误的想法
public:
    bool stoneGame(vector<int>& piles) {
        // 最佳是水平就是每次贪心的取最大值 <= 错误的思路，贪心策略存在问题 ， 3 2 10 4
        int head = 0, rear = piles.size() - 1;
        int ya_c = 0, li_c = 0;
        bool trun_ya = true;
        int cur;
        while(head < rear){
            if(piles[head] > piles[rear]){
                cur = piles[head];
                head++;
            }else{
                cur = piles[rear];
                rear--;
            }

            if(trun_ya) ya_c += cur; else li_c += cur;
            trun_ya = !trun_ya; 
        }
        return ya_c > li_c;
    }
};

