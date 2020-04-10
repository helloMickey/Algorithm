/*
1. 输入3个子串， 输出这3个子串的最大公共子串 。
2. 输入树的中序和后序排列，输出树的层次遍历。上机要求和评分规则：
第一题、黑盒测试，只要求程序按格式输出结果正确。
第二题、按照思路，规范编程，代码三方面综合考虑得分。
*/
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

//动态规划求解俩个字符串的子串
map<string, int> findSubstr(string a, string b){
	map<string, int> result;
	int a_l = a.length(), b_l = b.length();
	vector<vector<bool>> anb(b_l, vector<bool>(a_l));//二维数组大小为 b_l * a_l,视作b_l行，a_l列
	//动态规划
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
	//计算a和b中的所有字串
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
					result.insert(pair<string, int>(substr, 1));//第一次插入单个字符，之后再累加
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
		if(anc.find(it->first) != anc.end())//相同的字串
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