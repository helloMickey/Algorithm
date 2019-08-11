#include <iostream>
#include<stdio.h>
#include<string>
#include <vector>
using namespace std;
struct Result
{
    string label;
    float num;
};
Result getMax(float W, float T, float L)
{
    Result r;
    if (W > T)
    {
        if (W > L)
        {
            r.label = "W";
            r.num = W;
        }
        else
        {
            r.label = "L";
            r.num = L;
        }
    }
    else
    {
        if (T > L)
        {
            r.label = "T";
            r.num = T;
        }
        else
        {
            r.label = "L";
            r.num = L;
        }
    }
    return r;
}
int main()
{
    float W, T, L;
    int c = 3;
    vector<Result> choseList;
    while (c--)
    {
        cin >> W >> T >> L;
        choseList.push_back(getMax(W, T, L));
    }
    //cout <<std::fixed<< setpercision(2);
    cout << choseList[0].label <<" "<< choseList[1].label <<" "<< choseList[2].label <<" ";
    printf("%.2f", (choseList[0].num * choseList[1].num * choseList[2].num * 0.65 - 1) * 2);
    return 0;
}