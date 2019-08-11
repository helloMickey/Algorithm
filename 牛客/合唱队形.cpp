#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//动态规划求：最长上升子序列
void max_asc_sq(vector<int> &l, vector<int> &dp)
{
    //dp[i]: 以l[i]为结尾的最长上升子序列
    dp[0] = 1;
    for (int i = 1; i < l.size(); i++)
    {
        dp[i] = 1;
        for (int index = 0; index < i; index++)
        {
            if (l[i] > l[index] && dp[index] >= dp[i])
                dp[i] = dp[index] + 1;
        }
    }
}
void fun(){
    int N;
    cin >> N;
    vector<int> l(N, 0);
    int num;
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        l[i] = num;
    }
    
    vector<int> dp_asc(N, 0);
    vector<int> dp_desc(N, 0);

    max_asc_sq(l, dp_asc);
    //将ｌ[]逆序
    reverse(l.begin(), l.end());
    max_asc_sq(l, dp_desc);
    //将dp_desc[]逆序
    reverse(dp_desc.begin(), dp_desc.end());

    int result = N;
    int num_l, num_r;
    int pop_num;
    for(int i = 0; i < N; i++)
    {
        num_l = dp_asc[i];
        num_r = dp_desc[i];
        pop_num = N - (num_l + num_r - 1);//取出队伍的人：Ｎ　-　留在队中的人
        if(pop_num < result)
        {
            result = pop_num;
        }
    }
    cout << result << endl;
}
int main()
{
    fun();
}