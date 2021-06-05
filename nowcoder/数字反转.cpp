#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
#include<algorithm>
#include<vector>
using namespace std;

void fun_reverse()
{
    int a, b;
    vector<int> result; 
    while(cin >> a){
        cin >> b;
       //现在又任意两个正整数，问他们两个数反转的和是否等于两个数的和的反转。 
        int sum = a + b;
        string a_s, b_s, s_s;
        {
            ostringstream os;
            os << a ;
            a_s = os.str();
        }
        {
            ostringstream os;
            os << b ;
            b_s = os.str();
        }
        {
            ostringstream os;
            os << sum ;
            s_s = os.str();
        }
        reverse(a_s.begin(), a_s.end());       
        reverse(b_s.begin(), b_s.end());        
        reverse(s_s.begin(), s_s.end());
        
        int a_r = atoi(const_cast<char*>(a_s.c_str()));
        int b_r = atoi(const_cast<char*>(b_s.c_str()));        
        int s_r = atoi(const_cast<char*>(s_s.c_str()));
        
        if((a_r + b_r) == s_r)
            result.push_back(sum);
        else
            result.push_back(-1);
    }
    for(int i = 0;;){
        if(result[i] != -1)
            cout << result[i];
        else
            cout << "NO";
        i++;
        if(i<result.size())
            cout << endl;
        else
            break;
    }
}
//int main()
//{
//	fun_reverse();
//}