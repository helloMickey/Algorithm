/*
有一个神奇的口袋，总的容积是40，用这个口袋可以变出一些物品，这些物品的总体积必须是40。
John现在有n个想要得到的物品，每个物品的体积分别是a1，a2……an。
John可以从这些物品中选择一些，如果选出的物体的总体积是40，那么利用这个神奇的口袋，John就可以得到这些物品。
现在的问题是，John有多少种不同的选择物品的方式。
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(int a, int b)
{
    return a > b;
}
void fun_package()
{
    int n;
    cin >> n;
    int size = n; //物品数目
    vector<int> weight;
    int w;
    while (n--)
    {
        cin >> w;
        weight.push_back(w);
    }
    weight.insert(weight.begin(), -1);//在0位置插入一个元素
    int v = 40;//背包的容量为40
    vector<vector<int> > dp(v + 1, vector<int>(v + 1, 0));//dp[i][j]表示：前i个物品中，重量达j的情况数


	for(int i=1;i<=size;i++)
		dp[i][0] = 1;
        
    //有第一个物品情况下
    dp[1][weight[1]] =  1;
    for (int i = 2; i <= size; i++)
    {//dp[i][j]表示：前i个物品中，重量达j的情况数
        for(int j = 1; j <= v; j++)
        {
            if(j >= weight[i])
            {//没i的情况下重量为j的情况数 +　有ｉ情况下重量为ｊ-weight[i]的情况数
				dp[i][j] = dp[i-1][j] + dp[i-1][j-weight[i]];
            }
			else
            {//重量小于 weight[i] 肯定是不放物品i的
				dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[size][40];
    
}
int main()
{
    fun_package();
}