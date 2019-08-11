#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<set>
using namespace std;

//十进制数倒序后的十进制数
int reverseDecimalNum(int n)
{
	string list = "";
	//list.
	list += (n%10) + '0';
	while(n/10){
		n = n/10;
		//list.push_back(n%10);
		list += (n%10) + '0';
	}
	//string to char
	return atoi(list.c_str());
}
//十进制数求对应二进制倒序后对应的十进制
int reverseBinaryNum(int n){
	vector<int> bit_list;
	bit_list.push_back(n%2);
	while(n/2){
		n = n/2;
		if(n == 1)
		{
			bit_list.push_back(n%2);
			break;
		}
		bit_list.push_back(n%2);
	}
	//由反序的二进制得到十进制
	int len = bit_list.size();
	int result = 0;
	for(int i = 0; i < len; i++)
	{
		result += pow((float)2, len-i-1)*bit_list[i];
	}
	return result;
}
//判断一个数是不是质数；十万以内的质数
//bool isPrime[100001];
set<int> isPrime;
//快速构建质数表
void constructPrimeSet(){
	isPrime.insert(2);
	isPrime.insert(3);
	isPrime.insert(5);
	isPrime.insert(7);
	isPrime.insert(11);
	isPrime.insert(13);
	for(int i = 14; i < 100001; i++){
		for(set<int>::iterator j = isPrime.begin(); ; ){
			if(*j > sqrt((float)i))//超过根号i，i是质数
				isPrime.insert(i);;
			if((i % (*j)) == 0)//i 不是质数
				break;
			j++;
			if(j == isPrime.end())
			{//i 是质数
				isPrime.insert(i);
				break;
			}
		}
	}
}
bool isPrimeNum(int num){
	return isPrime.find(num) != isPrime.end() ;
}
//判断一个数是不是素数
bool isPrimeNum2(int num){
	for(int i = 2; i <= sqrt((float)num); i++){
		if(num%i == 0)
			return false;
	}
	return true;
}
void fun1015(){
	constructPrimeSet();
	vector<string> result;
	int a , b;
	cin >> a;
	while(a >= 0){
		cin >> b;
		if(b == 10)
		{
			if(isPrimeNum(a) && isPrimeNum(reverseDecimalNum(a)))
				result.push_back("Yes");
			else
				result.push_back("No");
		}
		if(b == 2)
		{
			if(isPrimeNum(a) && isPrimeNum(reverseBinaryNum(a)))
				result.push_back("Yes");
			else
				result.push_back("No");
		}
		cin >> a;
		if(a < 0)
			break;
	}
	for(vector<string>::iterator it = result.begin();;)
	{
		cout << *it;
		it++;
		if(it == result.end())
			break;
		cout << endl;
	}
}
//int main(){
//	fun1015();
//}