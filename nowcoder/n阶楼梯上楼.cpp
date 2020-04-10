#include <iostream>
using namespace std;
void fun_n(){
	int n;
    while(cin >> n){
        //«ÛF(n)
        if(n == 1)
            cout << "1";
        else if(n == 2)
            cout << "2";
        else{
            int pre = 1, cur = 2;
            int result = 3;
            for(int i = 3; i <= n; i++){
                result = cur + pre;
                pre = cur;
                cur = result;
            }
            cout << result;
        }
        cout << endl;
    }
}
//int main(){
//	fun_n();
//}