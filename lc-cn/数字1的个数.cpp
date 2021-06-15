/*
https://leetcode-cn.com/problems/number-of-digit-one/
*/

/*
作者：weierstras
链接：https://leetcode-cn.com/problems/number-of-digit-one/solution/shu-wei-dp-by-weierstras/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution_1 {
    #define mset(x,v) memset(x,(v),sizeof(x))
    #define rep(i,a,n) for(int i=(a);i<=(n);i++)
    #define ll long long
    #define maxn 15

    // a 记录数字的每一位
     // dp_i 表示 [0,10^i) 内有多少 1
    ll a[maxn], pw[maxn]={1}, dp[maxn]; 
    
    ll dfs(int pos, int cnt, bool limit){
        // pos 当前数位, cnt 当前递归的数中 1 的个数
        // limit 表示是否沿着上边界

        if(!pos) return cnt;
        
        if(~dp[pos] && !limit) return dp[pos] + cnt*pw[pos];
        
        ll ret=0, bound = limit? a[pos] : 9;

        rep(i,0,bound) ret += dfs(pos-1, cnt + (i==1), i==bound && limit);
        
        if(!limit) dp[pos]=ret;
        return ret;
    }
    ll solve(ll x){
        int len = 0;
        while(x) a[++len]=x%10, x/=10;
        mset(dp,-1);
        return dfs(len, 0, 1);
    }
public:
    int countDigitOne(int n) {
        rep(i,1,maxn-1) pw[i]=pw[i-1]*10;
        return solve(n);
    }
};

