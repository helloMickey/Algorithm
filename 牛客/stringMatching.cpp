#include<cmath>
#include<string>
#include<sstream>
#include<iostream>
using namespace std;
void fun_test()
{
    double pi = acos(-1);
    ostringstream os;
    os << pi;
    string pi_str = os.str();
    cout << pi_str << endl;
    pi_str = pi_str.substr(pi_str.find("."));
    cout << pi_str << endl;
}
void string_matching()
{
    string src, ptr;
    cin >> src >> ptr;
    int count = 0;
    int it = src.find(ptr);
    while(it != string::npos){
        count++;
        src = src.substr(it+1);
        it = src.find(ptr);
    }
    cout << count;
}
int main()
{
    string_matching();
}