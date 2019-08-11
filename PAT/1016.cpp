#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <math.h>
#include <stack>
#include <sstream>
using namespace std;

// 美分/每分钟
int fee_hour[24];

struct Record
{
    /* data */
    string date;
    int status;
    Record(string d, int s) : date(d), status(s){};
};
//按时间升序排列
bool compaerRecord(Record a, Record b)
{
    return a.date < b.date;
}
//计算费用
string getFee(Record come, Record out)
{
    //mm:dd:hh:mm
    string c = come.date, o = out.date;
    vector<string> c_list, o_list;
    char *l = strtok(const_cast<char *>(c.c_str()), ":");
    while (l)
    {
        c_list.push_back(l);
        l = strtok(NULL, ":");
    }

    l = strtok(const_cast<char *>(o.c_str()), ":");
    while (l)
    {
        o_list.push_back(l);
        l = strtok(NULL, ":");
    }
    int c_d, o_d, c_h, o_h, c_m, o_m;
    c_d = atoi(c_list[1].c_str());
    o_d = atoi(o_list[1].c_str()); 
    c_h = atoi(c_list[2].c_str());
    o_h = atoi(o_list[2].c_str());
    c_m = atoi(c_list[3].c_str());
    o_m = atoi(o_list[3].c_str());

    double fee = 0; int mins = 0;
    while (o_d != c_d) {//相差几天
        for(int i = 0; i < 24; i++)
        {
            fee += 60 * fee_hour[i] * 0.01;
        }
        c_d++;
        mins += 24*60;
    }
    
    if (c_h == o_h)
    {
        mins = o_m - c_m;
        //存的是美分; 美分/每分钟
        fee = mins * fee_hour[c_h] * 0.01;
    }
    else
    {

        while (c_h != o_h)
        {
            mins += 60 - c_m;
            fee += (float)(60 - c_m)  * fee_hour[c_h] * 0.01;
            c_h++;
            c_m = 0;
        }
        mins += o_m - c_m;
        fee += (float)(o_m - c_m)  * fee_hour[o_h] * 0.01;
    }
    //01:05:59 01:07:00 61 $12.10
    string mins_str, fees;
    ostringstream os;
    os << mins;  mins_str = os.str();
    ostringstream os_2;
    os_2 << fee;  fees = os_2.str();

    //fees保留两位小数
    int sub_len =  fees.find(".") + 3;
    string sum_str = fees.substr(0,  sub_len);
    if(sum_str.find(".") == sum_str.size() -2)
        sum_str +='0';

    return come.date.substr(3, 8) + " " + out.date.substr(3, 8) + " " + mins_str + " $"+ sum_str;
}

void fun1016()
{

    int n = 24;
    while (n--)
    {
        int a;
        cin >> a;
        fee_hour[24 - n - 1] = a;
    }
    int lines;
    cin >> lines;
    map<string, vector<Record> > bill_map;

    while (lines--)
    {
        string name, date, status_str;
        cin >> name >> date >> status_str;

        int status;
        if (status_str == "on-line")
            status = 1;
        else
            status = 0;

        map<string, vector<Record> >::iterator it = bill_map.find(name);
        if (it == bill_map.end())
        { //不在里面
            vector<Record> r_list;
            r_list.push_back(Record(date, status));
            bill_map.insert(pair<string, vector<Record> >(name, r_list));
        }
        else
        { //已经有
            it->second.push_back(Record(date, status));
        }
    }
    //string month ; 
    for (map<string, vector<Record> >::iterator i = bill_map.begin(); ; )
    {
        double sum = 0;
        //name month
        cout << i->first << " " <<i->second[0].date.substr(0, 2) << endl;

        vector<Record> list = i -> second;
        sort(list.begin(), list.end(), compaerRecord);
        
        stack<Record> status_stack; 
        status_stack.push(list[0]);
        for(int j = 1; j < list.size(); j++)
        {
            int statusNew = list[j].status;
            int stackTopStatus = status_stack.top().status;
            if(stackTopStatus == 1 && statusNew == 0){
                Record r = status_stack.top();
                //01:05:59 01:07:00 61 $12.10
                string billStr = getFee(r, list[j]);
                cout << billStr << endl;
                int pos = billStr.find("$");
                string fee = billStr.substr(pos+1, billStr.size() - pos -1);
                sum += atof(fee.c_str());
            }
            else
            {
                status_stack.push(list[j]);
            }
        }
        ostringstream os;
        os << sum;  string sum_str = os.str(); 
        if(sum_str.find(".") == sum_str.size() -2)
            sum_str +='0';
        cout << "Total amount: $" << sum_str;

        i++;
        if (i != bill_map.end()) {
            cout << endl;
        }else{
            break;
        }
    }
}
int main()
{

    fun1016();
}