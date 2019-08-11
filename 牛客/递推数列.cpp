/*
给定a0,a1,以及an=p*a(n-1) + q*a(n-2)中的p,q。这里n >= 2。 求第k个数对10000的模。
输入包括5个整数：a0、a1、p、q、k
第k个数a(k)对10000的模。
*/

#include<iostream>
using namespace std;
void  fun_(){
    int a0, a1, p, q, k;
    cin >> a0 >> a1 >> p >> q >> k;
    int an, an_1 = a1, an_2 = a0;
    for(int i = 2; i <= k; i++)
    {
        an = (p * an_1)%10000 + (q * an_2)%10000;
        an_2 = an_1;
        an_1 = an;
    }
    cout << an%10000;
}
int main()
{
    fun_();
}