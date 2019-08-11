#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;
/*
3 2 3
1 2
1 3
1 2 3
*/
bool cityMap[1001][1001] = {};
bool visit[1001] = {};
//城市数目从 1 开始记起
void travel(int i, int city)
{
    visit[i] = true;
    for (int j = 1; j <= city; j++)
    {
        //<i, j>之间能走通，且j没有被访问过
        if (cityMap[i][j] == true && visit[j] == false)
        {
            /* code */
            travel(j, city); //递归
        }
    }
}
void fun1013(){
    //memset(cityMap, false, 1001 * 1001 * 4);
    //memset(visit, false, 1001);
    for (int i = 0; i < 1001; i++)
    {
        for (int j = 0; j < 1001; j++)
        {
            cityMap[i][j] = false;
        }
    }
    for (int i = 0; i < 1001; i++)
    {
        visit[i] = false;
    }

    int city;
    int n, m, k;
    cin >> n >> m >> k;
    city = n;
    while (m--)
    {
        int i, j;
        cin >> i >> j;
        cityMap[i][j] = true;
        cityMap[j][i] = true;
    }
    vector<int> check_list;
    while (k--)
    {
        int repair;
        cin >> repair;
        check_list.push_back(repair);
    }
    vector<int> result;
    for (vector<int>::iterator it = check_list.begin(); it != check_list.end(); it++)
    {
        int repair = *it;
        visit[repair] = true; //该城市标记为访问过，在遍历的时候不再经过（意味被敌人占领）
        int count = 0;        //表示连通域的个数
        for (int i = 1; i <= city; i++)
        {
            if (false == visit[i])
            {
                //还没到达过
                count++;
                travel(i, city);
            }
        }
        result.push_back(count - 1); //n 连通域之间 只需 n-1 个边
                                     //全部标记为未访问，为下一轮做准备
        for (int i = 1; i <= city; i++)
        {
            visit[i] = false;
        }
    }
    for (vector<int>::iterator it = result.begin();;)
    {
        cout << *it;

        it++;
        if (it != result.end())
        {
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
    fun1013();
}
