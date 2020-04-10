#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int main(){
    int n;
    vector<int> max_result;
    vector<int> min_result;
    while(cin >> n){
        int max, min;
        int a, b;
        cin >> a >> b;
        max = ::max(a, b);
        min = ::min(a, b);
        n -= 2;
        int temp;
        while(n--){
           cin >> temp;
            if(temp > max)
                max = temp;
            else if(temp < min)
                min = temp;
        }
        max_result.push_back(max);
        min_result.push_back(min);
    }
    for(int i=0;;){
        cout << max_result[i] << " " << min_result[i];
        i++;
        if(i < max_result.size())
            cout << endl;
        else
        {
            break;
        }
        
    }
}