//��������N(N>1)���������ĸ����� ��ͬ����������Ҫ�ظ����㡣��120=2*2*2*3*5������5����������
#include<iostream>
#include<vector>
using namespace std;
void fun_prime()
{
	int prime_array[9] = {2,3,5,7,11,13,17,23,29};
	int n;
    vector<int> result;
	while(cin >> n)
	{
		int count = 0;
		int prime;
		for(int i = 0; i < 9; i++){
			prime = prime_array[i];
			while(n%prime == 0){
				count++;
				n = n/prime;
			}
			if( n == 1)
				break;
		}
		result.push_back(count);
	}
    for(int i = 0;;){
        cout << result[i];
        i++;
        if(i < result.size())
            cout << endl;
        else
            break;
    }
}
//int main()
//{
//	fun_prime();
//}