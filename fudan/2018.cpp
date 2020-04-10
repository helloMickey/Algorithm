#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <math.h>
#include <stack>
#include <sstream>
using namespace std;
void fnu2018(){ 
	//10x-2x-8=4x+7+x
	string e;
	cin >> e;
	string left, right;
	//e.replace(' ', "");//ȥ���ո�
	//getline(cin, e);
	//e.erase(0,e.find_first_not_of(" "));
	//e.erase(e.find_last_not_of(" ") + 1);
	int pos = e.find("=");
	left = e.substr(0, pos);
	right = e.substr(pos+1, e.size()-1);
	int a_x = 0, a_c = 0;

	vector<string> item_l, item_r;
	string left_copy = left, right_copy = right;
	char* sub_str = strtok(const_cast<char*>(left_copy.c_str()), "+-");
	while(sub_str){
		item_l.push_back(sub_str);
		sub_str = strtok(NULL, "+-");
	}
	sub_str = strtok(const_cast<char*>(right_copy.c_str()), "+-");
	while(sub_str){
		item_r.push_back(sub_str);
		sub_str = strtok(NULL, "+-");
	}
	//����Ⱥ����
	for(int i = 0; i < item_l.size(); i++)
	{
		string sub_item = item_l[i];
		int pos = left.find(sub_item);

		int isPositive = 1;
		//���ж�����
		if(left.find("+" + sub_item) != -1)
			isPositive = 1;
		else if(left.find("-" + sub_item ) != -1 )
			isPositive = -1;
		else if(left.find(sub_item ) != -1 )
			isPositive = 1;//�ڿ�ͷλ����

		if(sub_item.find("x") != -1){//��x��
			string temp = sub_item.substr(0, sub_item.find("x"));
			if(temp == "")
				temp = "1";
			a_x += isPositive * atoi(temp.c_str());
		}else{//����x
			a_c += isPositive * atoi(sub_item.c_str());
		}

	}
	//����Ⱥ��ұ�
	for(int i = 0; i < item_r.size(); i++)
	{
		string sub_item = item_r[i];
		int pos = right.find(sub_item);

		int isPositive = 1;
		//���ж�����
		if(right.find("+" + sub_item) != -1)
			isPositive = 1;
		else if(right.find("-" + sub_item ) != -1 )
			isPositive = -1; 
		else if(right.find(sub_item ) != -1 )
			isPositive = 1;//�ڿ�ͷ

		if(sub_item.find("x") != -1){//��x��
			string temp = sub_item.substr(0, sub_item.find("x"));
			if(temp == "")
				temp = "1";
			a_x += -1 * isPositive * atoi(temp.c_str());
		}else{//����x
			a_c += -1 * isPositive * atoi(sub_item.c_str());
		}
	}

	if(a_x == 0 && a_c == 0){
		cout << "infinite solutions" << endl;
	}else if(a_x == 0 && a_c != 0){
		cout << "no solution" << endl;
	}else{
		cout << "x = " << (-a_c)/a_x << endl; 
	}

}
//int main()
//{
//	while(true)
//		fnu2018();
//}