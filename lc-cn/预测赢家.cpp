// https://leetcode-cn.com/problems/predict-the-winner/
// 相关题目：石子游戏

class Solution { // 递归 ！！
// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/predict-the-winner/solution/yu-ce-ying-jia-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
public:
    bool PredictTheWinner(vector<int>& nums) {
        return total(nums, 0, nums.size() - 1, 1) >= 0; // 先手与后手之间的差 >= 0
    }

    int total(vector<int>& nums, int start, int end, int turn) { // 先手与后手之间的差
        if (start == end) {
            return nums[start] * turn;
        }
        int scoreStart = nums[start] * turn + total(nums, start + 1, end, -turn);
        int scoreEnd = nums[end] * turn + total(nums, start, end - 1, -turn);
        
        if(turn == 1){ // 先手尽可能拉开距离
            return std::max(scoreStart ,scoreEnd );
        }else{ // 后手尽可能缩小距离
            return std::min(scoreStart ,scoreEnd );
        }
    }
};

// 动态规划思路
// dp[i][j] 表示当数组 剩下的部分 为下标 i 到下标 j 时，当前玩家与另一个玩家的分数之差的最大值，
// 注意当前玩家不一定是先手

// dp[i][j] = max(num[i] - dp[i+1][j], nums[j] - dp[i][j-1])  //当前玩家会选择最优的方案，使得自己的分数最大化

class Solution { // DP
public:
    bool PredictTheWinner(vector<int>& nums) {
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



class Solution_MyError { // 最开始错误思路版
public:
    // int dict[20][20][2]; // l, r, play_numer。表示在 [l, r] 区间上，玩家1先取、后取能到的最大值
    vector<int> _nums;
    int f_turn = true;

    int dfs(int l, int r, bool f_turn){
        if(l > r) return 0;
        if(l == r) return _nums[l]; // 没得选；

        // 当前手一定选对自己最有利的    
        int l_value = dfs(l+1, r, !f_turn) + f_turn*_nums[l]; // 取左边的
        int r_value = dfs(l, r-1, !f_turn) + f_turn*_nums[r]; // 取右边的

        return max(l_value, r_value); // 记录先手其可以获得的最大值
    }
    bool PredictTheWinner(vector<int>& nums) {
        // 因为每个玩家只有两种可能，那么可以枚举所有的可能过程，这是一个DFS搜索的过程，可以通过剪枝进行优化
        /*
                    起始
                /           \
            玩家1取左     玩家1取右
            /       \
        玩2左       玩2右
        */
        // DFS的深度等于数组的长度，可以通过数组区间左右标记 + 玩家标号，记录已遍历的值 （这个剪枝的思路错了！！）

        _nums = nums;
        int sum = 0;
        for(int num: nums) sum+=num; // 总值
        int f_max_v = dfs(0, _nums.size()-1, true); // 先手能获得的最大值

        cout << f_max_v;

        return f_max_v > (sum > f_max_v);
    }
};