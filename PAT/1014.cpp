#include <deque>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
int queueSize;
int winSize;
//返回未满队的位置
//deque<int>::iterator windowsFull(vector< deque<int> > )
void fun1014()
{
    int N, M, K, Q;
    cin >> N >> M >> K >> Q;
    //N个窗口， 每个窗口可排人数 M人
    queueSize = M;
    winSize = N;
    vector<deque<int> > w_list(winSize, deque<int>(queueSize));
    vector<int> t_list;
    while (K--)
    {
        int t;
        cin >> t;
        t_list.push_back(t);
    }
    map<int, int> q_map;
    while (Q--)
    {
        int q;
        cin >> q;
        q_map.insert(pair<int, int>(q, -1)); //存入查询者的id
    }
    int count = 0;
    vector<int>::iterator it = t_list.begin();
    while (M--)
    {
        for (int i = 0; i < w_list.size() && it != t_list.end(); i++)
        {
            count++;
            w_list[i].push_back(*it);
            it++;
        }
    }
    //等待区有count个人
    if (it != t_list.end())
    {
        //等待区没排满
        for(map<int, int>::iterator i = q_map.begin(); i != q_map.end(); i++)
        {
            int n = i->first;
            int shang = n/winSize;
            int yu = n%winSize;
            int time_len = 0;
            for(int i = 0; i < shang; i++)
            {//排在自己前面的花的时间
                time_len += w_list[yu].front();
                w_list[yu].pop_front();
            }
            time_len += w_list[yu].front();//自己完成需要的时间
            w_list[yu].pop_front();

            q_map.insert(pair<int, int>(n, time_len));
        }
    }
    else
    {
        //等待区排满
    }
    //时间换算
    for(map<int, int>::iterator i = q_map.begin(); i != q_map.end(); i++)
    {
        
    }
    
}
int main()
{
}