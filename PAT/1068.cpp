#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool compare_fun(int a, int b){
	return a>b;
}
void fun1068(){
	int coins, money;
	cin >> coins >> money;
	int temp = coins;
	vector<int> wight;
	while(temp--)
	{
		int w;
		cin >> w;
		wight.push_back(w);
	}
	//降序排列；
	sort(wight.begin(), wight.end(), compare_fun);wight.insert(wight.begin(), -1);
	
	vector<int> dp(money+1, 0);//初试全为零 dp[v] = 0 / dp[0][n] = 0;
	
	vector<vector<bool> > choice(coins+1, vector<bool>(money + 1, false));//初始全为false
	
	int i = 1;
	while(i <= coins){
		for(int v = money; v >= wight[i]; v--){
			if(dp[v] <= dp[v - wight[i]] + wight[i])
			{
				dp[v] = dp[v- wight[i]] + wight[i];//dp[i][v] = dp[i-1][v-w[i]] + wight[i];
				//
				choice[i][v] = true;
			}
		}
		i++;	
	}
	if(dp[money] != money){//对于0-1背包而言 d[n][v]表示在容量为v时，n个物品中选择后可达到的最大值
		//当所选的总价不等于money时，表明money不能由n个coins通过选择而得到
		cout << "No Solution";
		return;
	}
	vector<int> arr;
	int v = money, index = coins;
	while(v > 0) 
	{
		if(choice[index][v] == true) 
		{
			arr.push_back(wight[index]);
			v -= wight[index];
		}
		index--;
	}
	for(int i = 0; i < arr.size(); i++) 
	{
		if(i != 0) 
			printf(" ");
		printf("%d", arr[i]);
	}
}

//int main()
//{
//	//fun1068();
//}
