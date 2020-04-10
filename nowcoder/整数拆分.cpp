//对于奇数n=2k+1：它的拆分的第一项一定是1，考虑去掉这个1，其实就对应于2k的拆分，因此f(2k+1)=f(2k).
//对于偶数n=2k：考虑有1和没有1的拆分。有1的拆分，与(2k-1)的拆分对应，与上面奇数的情况理由相同；
//没有1的拆分，将每项除以2，正好对应于k的所有拆分。因此f(2k)=f(2k-1)+f(k).
// --------------------- 
// 作者：stormpang 
// 来源：CSDN 
// 原文：https://blog.csdn.net/u012866328/article/details/52203066 
// 版权声明：本文为博主原创文章，转载请附上博文链接！
#include<iostream>
using namespace std;

int dp[1000001];
void fun_divide(){
    int n;
    cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++)
    {
        if(i%2 == 0)
        {//偶数
            dp[i] = dp[i-1] + dp[i/2];
        }else{
            dp[i] = dp[i-1];
        }
    }
    cout << dp[n]%1000000000;
}
int main()
{
    while(true){
        fun_divide();
    }
}