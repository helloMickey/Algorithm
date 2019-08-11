#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main(){

    int N, M, src, des;
    cin >> N >> M >> src >> des;
    cin.getline();//得到回车
    //城市人数
    int city_pNums[] = new int[N];
    int rescueNums[] = new int[N];//到达i城时可有的营救人数
    int shortestPahNUms[] = new int[N];//到该城时可有的最短路径数
    int N_temp  = N, i = 0;
    while(N_temp--){
        int pNums;
        cin >> pNums;
        city_pNums[i++] = pNums;
    }
    cin.getline();//得到回车

    vector<vector<int>> city_map = (N, vector<int>(N));//二位数组中必须要固定一维
    for(vector<int>::iterator i = city_map.begin(); i!=city_map.end(); i++)
        *i = -1;//初始全为 -1

    int M_temp = M; int maxPathLen = -1;
    while(M_temp--){
        int c1, c2, len;
        cin >> c1 >> c2 >> len;
        if (len > maxPathLen)
            maxPathLen = len;
        
        cin.getline();//得到回车
        city_map[c1][c2] = len;
    }
    maxPathLen++;

    if (city_map[src][des] ！= -1) {
        minLen = city_map[src][dec];
    }else{
        minLen = INT32_MAX;
    }
    //最终的结果
    int path_num = 0； int rescue_people = 0;
    //dijkstra思想
    set<int> S0, S1;
    S0.insert(src);
    for(int i = 0; i < N; i++)
        if (i != src)
            S1.insert(i);
    while(true){
        int city_index, minLen = maxPathLen;
        for(set<int>::iterator it = S1.begin(); it != S1.end(); it++)
        {
            //记录最小值,贪心
            if (city_map[src][*it] != -1 && city_map[src][*it] < minLen) {
                minLen = city_map[src][*it];
                city_index = *it;
            }
        }
        S1.erase(city_index);//删去该点

        if(city_index == des)//到达最短路径的目的地
        {
            break;
        }
        
        //更新路径
        for(set<int>::iterator it = S1.begin(); it != S1.end(); it++)
        {
            if( city_map[city_index][*it] == -1)
                continue;
            if (city_map[src][city_index] + city_map[city_index][*it] < city_index[src][*it]) {
                //进行更新
                city_map[src][*it] = city_map[src][city_index] + city_map[city_index][*it];
                path_num = 1;
            }
            if (city_map[src][city_index] + city_map[city_index][*it] == city_index[src][*it]) {
                    path_num++;
            }
        }
    }
    
}