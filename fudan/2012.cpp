 /*�����⡣
1��һ����Ŀ���������⡣1000���ɼ����ǰ30%����õ������������Ѱɡ�����QSORT�ġ�����һ��Ч�ʲ�ࡣҪ�����������ٴ󻰹��Ʋ����ˡ�
2.�ڶ�����Ŀ�Ƕ��������⡣����ڵ���ABCDE�����01234������ÿ�����������ı�š������Ҷ�Ӽ�ࡣ�����Ƚ�����Ȼ���������������ӵġ�
3.�ڶ�����Ӣ����Ŀ��Ϊ����ӦJYB�ĺ��١���ǿӢ�Ŀ��˰���������ˮ�⡣���Ǹ�һ���ַ�������ABC �ٸ�һ����������3.���AAABBBCCC�����ˡ�
��һ�������Ǻںв��ԡ���������֡��ڶ��������㷨˼�벽����֡�Ҫдע�͡�*/

#include <algorithm>
#include <time.h>
#include <random>
#include <map>
#include <iostream>
#include <string>
using namespace std;

//s1 С�� s2 ��ô����true�����򷵻�false
bool s1LessThanS2(string s1, string s2)
{
	return s1.length() < s2.length();
}
void fun2012()
{
	vector<int> list;
	srand(time(0));
	for(int i = 0; i < 10 ; i++)
		list.push_back(rand());
	::sort(list.begin(), list.end());
	vector<int>::iterator it = list.begin();
	while(it != list.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	vector<string> vs;
	vs.push_back("b");
	vs.push_back("a");
	vs.push_back("ahen");
	vs.push_back("c");
	::sort(vs.begin(), vs.end(),s1LessThanS2);
	vector<string>::iterator ptr = vs.begin();
	while(ptr != vs.end())
	{
		cout << *ptr << " ";
		ptr++;
	}
	cout << endl;

	map<string, int> m;
	m["a"] = 1;
	m["b"] = 2;
	m["chen"] = 3;
	m["chen"] = 3;
	m["chen"] = 3;
	m["ting"] = 2;
	m.insert(pair<string, int>("chenting", 1));
	//::sort(m.begin(), m.end(), s1LessThanS2); //map�޷���key�������򣡣���û�����壿����
	map<string, int>::iterator m_it = m.begin();
	while(m_it != m.end()){
		cout << "key: " << m_it->first <<", value: "<< m_it->second <<endl;
		m_it++;
	}
}
//int main()
//{
//	fun2012();
//	string a ="chen";
//}