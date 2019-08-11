/*
给出一个整数序列S，其中有N个数，定义其中一个非空连续子序列T中所有数的和为T的“序列和”。 
对于S的所有非空连续子序列T，求最大的序列和。 
变量条件：N为正整数，N≤1000000，结果序列和在范围（-2^63,2^63-1）以内。
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void max_sub_sequence()
{
    int n;
    while(cin >> n){
        vector<int> A;
        int temp, min_num = 0;
        while(n--){
            cin >> temp;
            A.push_back(temp);
            if (temp < min_num) {
                min_num = temp;
            }
            
        }
        A.insert(A.begin(), -1);//在第零个位置插入一个负数

        vector<int> dp(A.size()+1);
        fill(dp.begin(), dp.end(), 0);

        for(int i = 1; i <= A.size(); i++)
        {
            //以第i个位置数字为序列结尾的最大子序列
            dp[i] = max(dp[i-1] + A[i], A[i]);

        }
        
        int max_num = min_num;
        for(int i = 1; i <= A.size(); i++)
        {
            //遍历求出最大值
            if (dp[i] > max_num) {
                max_num = dp[i];
            }
        }
        
        cout << max_num << endl;
    }
    
}
int main()
{
    max_sub_sequence();
}