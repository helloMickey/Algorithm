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
			if ('1' <= s[i] && s[i] <= '9')//��һ�����ֲ�Ϊ 0
			{
				int k = i;
				while (s[i] <= '9' && s[i] >= '0')//
					i++;
				//i ָ��һ���ַ�
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
				//��ǰ i �±�ָ�� ']'
				string sub_str = decodeString(s.substr(k + 1, i - (k + 1)));
				i++;
				while (nums--)//�������������ظ�n��
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