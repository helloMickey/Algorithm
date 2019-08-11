#include<iostream>
#include<string>
#include<vector>
using namespace std;

void fun1040(){
	string str;
	getline(cin, str);
	int len = str.size();

	vector<vector<int> > dp(len, vector<int>(len));
	int max = 1, index_i = 0, index_j = 0;
	for(int i = len - 1; i >= 0 ; i--)
	{
		for(int j = i; j < len; j++)
		{
			if(i == j)
				dp[i][j] = 1;
			else if(str[i] == str[j]){
				if((j - i) == 1)
					dp[i][j] = 1;
				else if(dp[i+1][j-1] == 0)
					dp[i][j] = 0;
				else
					dp[i][j] = dp[i+1][j-1] + 1;
			}else
				dp[i][j] = 0;
			if(dp[i][j] >= max ){
				max = dp[i][j];
				//有更新时记录i,j的下表
				index_i = i;
				index_j = j;
			}
		}
	}

	cout << index_j - index_i + 1;
}
//int main()
//{
//	while(true)
//		fun1040();
//}