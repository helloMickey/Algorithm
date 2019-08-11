/*
有若干张邮票，要求从中选取最少的邮票张数凑成一个给定的总值。    
 如，有1分，3分，3分，3分，4分五张邮票，要求凑成10分，则使用3张邮票：3分、3分、4分即可。
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(int a, int b){
    return a > b ;
}
void fun_stamp()
{
    int sum;
    while(cin >> sum){
        int n;
        cin >> n;
        int size = n;//邮票数目
        vector<int> wight;
        int w; 
        while(n--){
            cin >> w;
            wight.push_back(w);
        }
        sort(wight.begin(), wight.end(), compare);//用一位数组来表示dp[][], 将权重矩阵倒排
        
        vector<int> dp(sum + 1);
        
        fill(dp.begin(), dp.end(), 0);//dp[0][n]初始为0
        wight.insert(wight.begin(), -1);
        vector<vector<bool> > choice(size + 1, vector<bool>(dp.size(), false));//大小为(i+1)*(v+1)的矩阵
        for(int i = 1; i <= size; i++)
        {
            for(int v = sum; v >= wight[i]; v--)
            {
                if(dp[v] < (dp[v-wight[i]] + wight[i]))
                {
                    //选择物品i， dp[i][v] = dp[i-1][v-wight[i]] +　wight[i]；
                    dp[v] = dp[v-wight[i]] + wight[i];
                    choice[i][v] = true;

                }else
                {
                    dp[v] = dp[v];//不选物品i， dp[i][v] = dp[i-1][v]；
                }

            }
            
        }
        if (dp[sum] != sum) {
            cout << 0 ;
        }else
        {
            int stamps = size;
            int count = 0;
            for(int i = 1; i <= stamps; i++)
            {
                if (choice[i][sum] == true) {
                    count++;
                }
            }
            cout << count;
            
        }
        cout << endl;
    }
    
}
int main()
{
    fun_stamp();
}
