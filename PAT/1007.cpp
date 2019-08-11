#include<iostream>
#include<vector>
using namespace std;
const int K = 10000;
void fun1007(){
	//int arrayNum[K][K] = {};
	int arrayNum[K] = {};
	int size;
	cin >> size;
	int n = 0;
	while(n < size){
		int number;
		cin >> number;
		arrayNum[n] = number;
		n++;
	}
	int maxSum = arrayNum[0], index_x = 0, index_y = 0;
	int result[K] = {};
	for(int i = 0; i < size; i++){
		result[i] = arrayNum[i];
		if(result[i] > maxSum){
			maxSum = result[i];
			index_x = 0, index_y = i;
		}
	}
	for(int i  = 1; i < size; i++){
		int pre = result[i-1], cur = 0;
		for(int j = i; j < size; j++){
			cur = result[j];
			result[j] = pre + arrayNum[j];
			pre = cur;
			//!!!! д�� >= ������Ӵ������� sum ��󣬲����ִ������
			//!!!! ���֮д�� > ������Ӵ�sum ���, ����һ�������
			if(result[j] >= maxSum){
				maxSum = result[j];
				index_x = i, index_y = j;
			}
			else if(result[j] == maxSum){
				//�������£�ѡȡ�ĶΣ�����ѡ�ȽϿ�ǰ���ִ��ҳ��Ƚ϶̵��ִ�
				if(i < index_x){
					maxSum = result[j];
					index_x = i, index_y = j;
				}
			}
		}
	}
	cout <<maxSum<< " " <<arrayNum[ 0 + (index_y - index_x)] << " " << arrayNum[index_y] ;
}
//int main(){
//	fun1007();
//}