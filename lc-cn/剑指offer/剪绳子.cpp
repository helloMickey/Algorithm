// https://leetcode-cn.com/problems/jian-sheng-zi-lcof/

/*
动态规划：
dp[i] 表示长度为 n 绳子分段后的最大乘机结果（也就是答案值）。
dp[i] = max(dp[i-j] * dp[j]) j 取 1 到 i/2 之间。 =》 尝试不同的分段点，取结果最大的一个

数论：
任何大于1的数都可由2和3相加组成（根据奇偶证明）
因为2*2=1*4，2*3>1*5, 所以将数字拆成2和3，能得到的积最大
因为2*2*2<3*3, 所以3越多积越大 时间复杂度O(n/3)，
用幂函数可以达到O(log(n/3)), 因为n不大，所以提升意义不大，我就没用。 空间复杂度常数复杂度O(1)
双百解法，简单的数论题，DP并不是最优解
*/

class Solution { // 动态规划
public:
    int cuttingRope(int n) {
        // n<=3的情况，m>1必须要分段，例如：3必须分成1、2；1、1、1 ，n=3最大分段乘积是2, 同理2的最大乘积为1
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        vector<int> dp(n+1);
        /*
        下面3行是n>=4的情况，跟n<=3不同，4可以分很多段，比如分成1、3，
        这里的3可以不需要再分了，因为3分段最大才2，不分就是3。记录最大的。
         */
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for(int i = 4; i <= n; i++) {
            int maxValue = 0;//记录最大的
            //j<=i/2是因为1*3和3*1是一样的，没必要计算在内，只要计算到1*3和2*2就好了
            for(int j = 1; j <= i/2; j++) {
                maxValue = max(maxValue, dp[j] * dp[i-j]);
                /*
                这样的状态转移方程貌似更为全面一些？？
                     len[i] = max(len[i],max(len[j]*len[i-j],max(j*(i-j),max(len[j]*(i-j),j*len[i-j]))));
                    /*max(长度为i的绳子剪开的乘积，
                    长度为j的绳子*长度为i-j的绳子，
                    长度为j的绳子*长度为i-j的绳子剪开的乘积，
                    长度为j的绳子剪开的乘积*长度为i-j的绳子剪开的乘积，
                    长度为j的绳子剪开的乘积*长度为i-j的绳子)
                */         
            }
            dp[i] = maxValue;
        }
        return dp[n];
    }
};

int cuttingRope(int n) { // 数论方法：
    return n <= 3? n - 1 : pow(3, n / 3) * 4 / (4 - n % 3); // 注意，这里 4 / (4 - n % 3) 不能用括号括起来！
}