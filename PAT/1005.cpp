#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string in;
    cin >> in;
    int result = 0;
    for(string::iterator it = in.begin(); it != in.end(); it++)
    {
        char bit_str = *it;
        int bit_num =  bit_str - '0';
        result += bit_num;
    }
    string output[] = {"zero", "one", "tow", "three", "four", "five","six","seven","eight","nine"};
    if (result == 0) {
        cout<<"zero";
        return 0;
    }
    vector<int> result_list;
    while(result % 10){
        int temp = result % 10;
        result_list.push_back(temp);
        result = result / 10;
    }
    reverse(result_list.begin(), result_list.end());
    vector<int>::iterator it;
    for(it = result_list.begin(); it != (result_list.end() - 1); it++)
    {
        cout << output[*it] << " ";
    }
    cout << output[*it];
    return 0;
}