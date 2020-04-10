/*
1. ����3���Ӵ��� �����3���Ӵ�����󹫹��Ӵ� ��
2. ������������ͺ������У�������Ĳ�α������ϻ�Ҫ������ֹ���
��һ�⡢�ںв��ԣ�ֻҪ����򰴸�ʽ��������ȷ��
�ڶ��⡢����˼·���淶��̣������������ۺϿ��ǵ÷֡�
*/
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

//��̬�滮��������ַ������Ӵ�
map<string, int> findSubstr(string a, string b){
	map<string, int> result;
	int a_l = a.length(), b_l = b.length();
	vector<vector<bool>> anb(b_l, vector<bool>(a_l));//��ά�����СΪ b_l * a_l,����b_l�У�a_l��
	//��̬�滮
	for(int i = 0; i < b_l ; i++)
	{
		for(int j = 0; j < a_l; j++)
		{
			if(a[j] == b[i])
				anb[i][j] = true;
			else 
				anb[i][j] = false;
		}
	}
	//����a��b�е������ִ�
	for(int i = 0; i < b_l; i++)
	{
		for(int j = 0; j < a_l; j++)
		{
			if(true == anb[i][j])
			{
				string substr = "";
				int iTemp = i, jTemp = j;
				while(iTemp < b_l && jTemp < a_l)
				{
					if(true != anb[iTemp][jTemp])
						break;
					substr += a[jTemp];
					result.insert(pair<string, int>(substr, 1));//��һ�β��뵥���ַ���֮�����ۼ�
					iTemp++; jTemp++;
				}
			}
		}
	}
	return result;
}
void function(){
	string a, b, c;
	cin >> a >> b >> c;

	map<string, int> anb, anc;
	anb = findSubstr(a, b);
	anc = findSubstr(a, c);


	map<string, int> substrList; //<"substr", length>
	map<string, int>::iterator it = anb.begin();
	while(it != anb.end())
	{
		if(anc.find(it->first) != anc.end())//��ͬ���ִ�
			substrList.insert(pair<string, int>(it->first, it->first.length()));
		it++;
	}

	string maxSubstr = ""; int maxLength = 0;
	map<string, int>::iterator t = substrList.begin();
	while(t != substrList.end())
	{
		if(t->second > maxLength){
			maxLength = t->second;
			maxSubstr = t->first;
		}
		t++;
	}
	cout << maxSubstr << endl;
}
//int main(){
//	function();
//	/*map<string, int> m;
//	m.insert(pair<string, int>( "chen", 100));
//	m.insert(pair<string, int>( "chen", 2));
//	m["chn"] = 1;
//	if(m.find("chn") != m.end())
//		cout << "aaaaaaaaaaaaa" << endl;
//	if(m.count("chn") == 1)
//		cout << "aaaaaaaaaaaaa" << endl;
//
//	cout << m["chen"] <<endl;*/
//}