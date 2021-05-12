// https://leetcode-cn.com/problems/unique-binary-search-trees/

class Solution {
public:
    long factorial(int n){
        long res = 1;
        for (int i = 1; i <= n; i++)
        {
            res *= i;
        }
        return res;
    }
    int numTrees(int n) {
        // 等价于：给定一个先序遍历结果，求可能的后续遍历结果的可能数: C(2n,n) / (n+1) . C(a, b) = A(a, b)/ b! = a! / b!*(a-b)!
        // G(n) = G(0)*G(n-1)+G(1)*(n-2)+...+G(n-1)*G(0) = (2n)! / n!*n! /(n+1)
        return factorial(2*n) / (factorial(n) * factorial(n) * (n+1)); // 阶乘这里存在溢出的风险
    }
};
class Solution_2 {
// 链接：https://leetcode-cn.com/problems/unique-binary-search-trees/solution/96-bu-tong-de-er-cha-sou-suo-shu-dong-ta-vn6x/
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                // G(n) = G(0)*G(n-1)+G(1)*(n-2)+...+G(n-1)*G(0) 
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};