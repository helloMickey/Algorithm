#include<iostream>
#include<vector>
#include<set>
#include<memory.h>
#include<algorithm>
using namespace std;
const int K = 2001;
void fun1009(){
//2 1 2.4 0 3.2
//2 2 1.5 1 0.5
	float a[1000] = {};
	vector<int> index_a;
	float b[1000] = {};
	vector<int> index_b;
	float result[K] = {};
	bool result_flag[K];
	memset(result_flag, false, sizeof(result_flag));//初始化为false
	set<int> index_result;

	int n; cin >> n;
	int n_temp = n;
	while(n_temp--){
		int N; float A;
		cin >> N >> A;
		a[N] = A;
		index_a.push_back(N);
	}
	int m; cin >> m;
	int m_temp = m;
	while(m_temp--){
		int N; float A;
		cin >> N >> A;
		b[N] = A;
		index_b.push_back(N);
	}
	//int count = 0;
	if(0 == n){//
		for(auto i = index_b.begin(); i != index_b.end(); i++)
		{
			int t = *i;
			index_result.insert(t);
			result[t] =  b[t];
			result_flag[t] = true;
		}
	}
	if(0 == m){//
		for(auto i = index_a.begin(); i != index_a.end(); i++)
		{
			int t = *i;
			index_result.insert(t);
			result[t] =  a[t];
			result_flag[t] = true;
		}
	}
	for(auto i = index_a.begin(); i != index_a.end(); i++){
		int i_index = *i;
		for(auto j = index_b.begin(); j != index_b.end(); j++){
			//指数相加，结果相乘
			int j_index = *j;
			int t = i_index + j_index;//结果的指数
			index_result.insert(t);
			result[t] += (a[i_index] * b[j_index]);
			result_flag[t] = true;
		}
	}
	//sort( index_result.begin(), index_result.end());
	cout << index_result.size();
	/*for(auto i = index_result.begin(); i != index_result.end(); i++)
		cout<<" " << *i <<" " <<result[*i];*/
	
	for(int i = 2000; i >= 0; i--){
		if(result_flag[i] == true)
			printf(" %i %.1f", i, result[i]);
			//cout <<" " <<  i << " " << result[i];
	}
}
//int main(){
//	fun1009();
//}