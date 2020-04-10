#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void fun_largest_subsequence()
{
    /*
    abcd
    cxbydz
    */
   string s1, s2;
   cin >> s1 >> s2;
   int i_l = s1.size() + 1, j_l = s2.size() + 1;
   vector<vector<int> > dp(i_l, vector<int>(j_l, 0));
   s1.insert(s1.begin(),'0'); s2.insert(s2.begin(),'0');
   int result = 0;
   //dp[i][j],字符串s1第i个位置字符之前 与 字符串s2第j个位置之前 最长公共子序列的长度
   for(int i = 1; i < i_l; i++)
   {
       for(int j = 1; j < j_l; j++)
       {
           //动态规划，转移方程
           if (s1[i] == s2[j]) {
               dp[i][j] = dp[i-1][j-1] + 1;
           }else
           {
               dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
           }
           //if (dp[i][j] > result) {
               //result = dp[i][j];
           //}
       }
       
   }
   cout << result;
   
}
int main(){
    fun_largest_subsequence();
}