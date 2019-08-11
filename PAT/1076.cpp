#include<set>
#include<vector>
#include <algorithm>
#include<string>
#include<cmath>
#include<map>
#include<iterator>
#include<queue>
#include<iostream>
using namespace std;
/*
7 3
3 2 3 4
0
2 5 6
2 3 1
2 3 4
1 4
1 5
//2 2 6
*/

void fun1076()
{
	//int G[1001][1001];

	int level;
	int nodes, k, col = 1;
	cin >> nodes >> level;
	
	vector<vector<int> > G(nodes+1, vector<int>(nodes+1));

	for(int i=0;i<= nodes;i++)
		for(int j=0;j<= nodes;j++)
			G[i][j]=false;	

	int temp_node = nodes;
	while(temp_node--)
	{
		cin >> k;
		while(k--)
		{
			int row;
			cin >> row;
			G[row][col] = true;
		}
		col++;
	}

	vector<int> query_list;
	int q_size, q_id;
	cin >> q_size;
	while(q_size--)
	{
		cin >> q_id;
		query_list.push_back(q_id);
	}
	vector<int> result_list;
	for(int i=0; i< query_list.size(); i++)
	{
		int find_id = query_list[i];
		int temp = level;
		set<int> spread;
		queue<int>level_spread;level_spread.push(find_id);
		//只可以传播level层
		int layer_size = 1;
		while(!level_spread.empty())
		{
			if(layer_size == 0){
				layer_size = level_spread.size();
				temp--;
			}
			if(temp == 0)
				break;
			layer_size--;

			int row_id = level_spread.front(); level_spread.pop();
			for(int cols = 0; cols <= nodes; cols++){
				if(G[row_id][cols] == true){//可传播
					level_spread.push(cols);
					spread.insert(cols);
				}
			}

		}
		int result;
		if(spread.find(find_id)==spread.end())
			result = spread.size();//发送者的不在转发集合里
		else
			result = spread.size() - 1;//自己不能转发自己的博文
		result_list.push_back(result);
	}
	//输出
	for(int i = 0;;)
	{
		cout << result_list[i];
		i++;
		if(i < result_list.size())
			cout << endl;
		else
			break;
	}
}
//int main()
//{
//
//}