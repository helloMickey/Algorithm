//从两个阵营中选择最小的桥<i, j>存在的问题: src到达不了i
//直接使用Dijkstra不能得到满足题意的解

#include <iostream>
#include <set>
#include <vector>
using namespace std;
void fun_goHome()
{
    vector<int> result;
    int citys;
    while (cin >> citys)
    {
        if(citys == 0)
            break;
        set<int> r;

        vector<vector<int> > city_map(citys + 1, vector<int>(citys + 1, -1)); //下标从0计记
        int roads;
        cin >> roads;
        int temp = roads;
        int max_w = -1; int sum_w =0;
        while (temp--)
        { //输入所有边
            int i, j, w;
            cin >> i >> j >> w;
            city_map[i][j] = w;
            city_map[j][i] = w;

            sum_w += w;
            if (w > max_w)
                max_w = w;
        }
        temp = citys;
        while (temp--)
        { //输入所有城市的label: 正、反
            int label;
            cin >> label;
            //
        }
        int src = 1, des = 2;
        vector<int> len(citys + 1, sum_w + 1);//初始位全不可达
        for (int i = 1; i <= citys; i++)
        { //初始化len
            if(city_map[1][i] == -1)
                len[i] = sum_w + 1  ;//len[i]赋值一个很大的数表示不可达
            else
                len[i] = city_map[1][i];
        }
        r.insert(1);
        int it = citys - 1;

        while (it--)
        {
            int min_w = sum_w + 1;//给min附一个很大的值
            int next;
            //选出len[] 中最小的值
            for (int j = 1; j <= citys; j++)
            {
                int w = len[j]; 
                if (w != -1 && r.find(j) == r.end() && w < min_w)
                {//从还进入S，并且可达的点中选出最小的
                    min_w = w;
                    next = j;
                }
            }

            r.insert(next);
            if(next == des){
                result.push_back(min_w);
                break;
            }

            //以next为中间节点看能否缩短路径
            for(int j = 1; j <= citys; j++)
            {
                if(r.find(j) == r.end()){
                    if (city_map[next][j] != -1 && (len[next] + city_map[next][j]) < len[j])  
                    {
                        len[j] = len[next] + city_map[next][j];
                    }
                }
                else {
                    continue;
                }
            }


        }
    }
     for(int i = 0;;)
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
    fun_goHome();
}