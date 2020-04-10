//求在总花费为c的情况下，所选物品能获取的最大评分s
//dp[i][v]:在前i个物品中，当花费为v时能获得的最高评分
//dp[i][v] =  max{dp[i-1][v], de[i-1][v-cost[i]] + score[i]}
#include<iostream>
#include<vector>
using namespace std;

void food_choice()
{
    vector<int> result;
    int C, N;
    while( cin >> C){
        cin >> N;
        int temp = N;
        vector<int> cost;
        vector<int> score;
        int c, s;
        while(temp--){
            cin >> c >> s;
            cost.push_back(c);
            score.push_back(s);
        }
        
        //从下标1开始
        cost.insert(cost.begin(), -1);
        score.insert(score.begin(), -1);
        vector<vector<int> > dp(N+1, vector<int>(C+1, 0));//dp[][]初始全为零

        for(int i = 1; i <= N; i++)
        {//N个菜品
            for(int v = 1; v <= C; v++)
            {
                if(v < cost[i])
                {//当前v买不到物品i
                    dp[i][v] = dp[i-1][v];
                }
                else if (dp[i-1][v] > (dp[i-1][v-cost[i]] + score[i]))
                {
                    dp[i][v] = dp[i-1][v];//不选物品i 获得的总评分更高
                }
                else
                {
                    dp[i][v] = dp[i-1][v-cost[i]] + score[i];//选物品i 获得的总评分更高
                }
                
            } 
        }
        //cout << dp[N][C] ;//输出前N个物品中，总价为C时所能获得的最大总评分
        result.push_back(dp[N][C]);
    }
    
   for(int i = 0; ;)
   {
       cout << result[i];

       i++;
       if (i < result.size()) {
           cout << endl;
       }
       else
       {
           break;
       }
   }
}
int main()
{
    food_choice();
}