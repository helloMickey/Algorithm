#include <vector>
#include <iostream>
#include <string>
#include <stack>
//#include <sstream>
using namespace std;
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> nums;
		for (int i = 0; i < tokens.size(); i++)
		{
			string t = tokens[i];
			int n1, n2;
			switch (t[0])
			{
			case '+':
				n1 = nums.top(); nums.pop();
				n2 = nums.top(); nums.pop();
				nums.push(n2 + n1);
				break;
			case '*':
				n1 = nums.top(); nums.pop();
				n2 = nums.top(); nums.pop();
				nums.push(n2 * n1);
				break;
			case '/':
				n1 = nums.top(); nums.pop();
				n2 = nums.top(); nums.pop();
				nums.push(n2 / n1);
				break;
			default:
				break;
			}

			if (t[0] == '-' && t.length() ==1)
			{//减号
				n1 = nums.top(); nums.pop();
				n2 = nums.top(); nums.pop();
				nums.push(n2 - n1);
			}
			else if(t[0] == '-')
			{//复数

				int num = stoi(t.substr(1, t.length() - 1));
				/*istringstream str(t.substr(1, t.length() - 1));
				int num;
				str >> num;*/
				nums.push(0 - num);
			}
			else if('0' <= t[0] && t[0] <= '9')
			{//正数
				/*istringstream str(t.substr(1, t.length() - 1));
				int num;
				str >> num;*/
				int num = stoi(t.substr(0, t.length()));
				nums.push(num);
			}
		}
		return nums.top();
	}
};
//模板函数：将string类型变量转换为常用的数值类型（此方法具有普遍适用性） 
template <class Type>
Type stringToNum(const string& str) {
	istringstream iss(str);
	Type num;
	iss >> num;
	return num;
}
//int main() {
//	vector<string> test;
//	test.push_back("2");
//	test.push_back("1");
//	test.push_back("+");
//	test.push_back("3");
//	test.push_back("*");
//	Solution obj;
//	cout << obj.evalRPN(test) <<endl;
//	system("pause");
//}