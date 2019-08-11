/*
玛雅人有一种密码，如果字符串中出现连续的2012四个数字就能解开密码。
给一个长度为N的字符串，（2=<N<=13）该字符串中只含有0,1,2三种数字，问这个字符串要移位几次才能解开密码，
每次只能移动相邻的两个数字。例如02120经过一次移位，可以得到20120,01220,02210,02102，其中20120符合要求，
因此输出为1.如果无论移位多少次都解不开密码，输出-1。
*/
/*
构造状态转化图，出发点-》交换一次-》交换两次-》。。。
*/
#include <iostream>
#include<string>
#include<map>
#include<queue>
#include<vector>
using namespace std;

int solve(string str, string pattern){
    map<string, int> status_m;
    status_m.insert(make_pair(str, 1));
    queue<string> status_q;

    //BFS
    status_q.push(str);
    int steps = 0;
    int layer_size = 1;
    while (!str.empty())
    {
        string cur = status_q.front(); status_q.pop();//出队
        if (cur.find(pattern) != string::npos) {
            //cur中有pattern子串；
            break;
        }
        //转移状态入队
        for (size_t i = 0; i < str.size() - 1; i++)
        {
            //交换 i 与 i+1位置上的字符串
            string tranform_status = str;
            char pos = tranform_status[i];
            char pos1 = tranform_status[i+1];
            tranform_status = tranform_status.substr(0, i) + pos1 + pos + tranform_status.substr(i+2, tranform_status.size() - (i+2));
            
            if(status_m.find(tranform_status) == status_m.end()){//该状态未出现过
                status_q.push(tranform_status);
                status_m.insert(make_pair(tranform_status, 1));
            }else{//该状态出现过
                //nothing
            }
        }

        layer_size--;
        if (layer_size == 0)
        { //一圈遍历完了
            steps++;
            layer_size = status_q.size();
        }
    }

    return steps;
}
void fun_maya()
{
    int size;
    vector<string> query;
    //while (cin >> size)
   // {
       cin >> size;
        string str;
        cin >> str;
        query.push_back(str);
    //}
    for (int i = 0;;)
    {
        cout << solve(query[i], "2012");

        i++;
        if (i < query.size())
            cout << endl;
        else
            break;
    }
}
// int main()
// {
//    fun_maya();
// }