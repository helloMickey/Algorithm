 /*三道题。
1第一道题目是排序问题。1000个成绩输出前30%。最好的做法是用最大堆吧。我用QSORT的。算了一下效率差不多。要是数据量的再大话估计不行了。
2.第二道题目是二叉树问题。比如节点是ABCDE编号是01234，给出每个左右子树的编号。求最大叶子间距。我是先建树，然后左右子树深度相加的。
3.第二道是英文题目，为了响应JYB的号召。加强英文考核啊。不过是水题。就是给一个字符串比如ABC 再给一个整数比如3.输出AAABBBCCC就行了。
第一第三道是黑盒测试。按结果给分。第二道根据算法思想步骤给分。要写注释。*/

#include <algorithm>
#include <time.h>
#include <random>
#include <map>
#include <iostream>
#include <string>
using namespace std;

//s1 小于 s2 怎么返回true，否则返回false
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
	//::sort(m.begin(), m.end(), s1LessThanS2); //map无法按key进行排序！！！没有意义？？？
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