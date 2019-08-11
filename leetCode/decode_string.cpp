#include <string>
#include <stack>
#include <iostream>
using namespace std;
class Solution {
public:
	string decodeString(string s) {
		string result = "";
		for (int i = 0; i < s.length(); )
		{
			int nums = 0;
			if ('1' <= s[i] && s[i] <= '9')//第一个数字不为 0
			{
				int k = i;
				while (s[i] <= '9' && s[i] >= '0')//
					i++;
				//i 指向一个字符
				nums = stoi(s.substr(k, i-k));
			}
			if (s[i] == '[') {
				int k = i;
				int p = -1;
				while (s[i] != ']' || p > 0 ) {
					if (s[i] == '[')
						p++;
					if (s[i] == ']')
						p--;
					i++;
				}
				//当前 i 下标指向 ']'
				string sub_str = decodeString(s.substr(k + 1, i - (k + 1)));
				i++;
				while (nums--)//将括号中内容重复n次
					result += sub_str;
			}
			else {
				result += s[i];
				i++;
			}
		}
		return result;
	}
};
//int main() {
//	string t = "10[a]";
//	Solution obj;
//	cout << obj.decodeString(t) << endl;
//	system("pause");
//}