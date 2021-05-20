// https://leetcode-cn.com/problems/basic-calculator/

// 这个代码目前其实存在一些问题，正确解法见 基本计算器2.cpp

class Solution {
	int _cal(int a, int b, char op) {
		switch (op) {
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
		default:
			return 0;
		}
	}
public:
	int calculate(string s) {
		// + -  ) 字符，对数字和操作进行弹出, 对栈进行弹出计算表达式结果
		// * /  ( digitals 直接入栈

		// 剔除string中的空格
		auto p = s.find(' '); // find_first_of
		while (p != string::npos) {
			s.replace(p, 1, "");
			p = s.find(' ');
		}

		stack<int> nums;
		stack<char> ops;
		string cur_num = "";
		char prev_ch = '!';
 		for (char ch : s) {
			if (ch >= '0' && ch <= '9') {
				cur_num += ch; // 数字可能由多位组成
			}
			else {
				// 数字入栈
				if (cur_num != "") {
					nums.push(atoi(cur_num.c_str()));
					cur_num = "";
				}
				else if (ch != '(' & prev_ch != ')') { // 说明此处出现连续的符号
					// 说明出现 "-2+ 1" "1-(+1+1)" 特殊情况的处理
					nums.push(0);
				}


				if (ch == ' ') {
					// do nothing
				}
				else if (ch == '+' || ch == '-') {
					// 弹出前缀计算表达
					while (!ops.empty() && ops.top() != '(') {
						// 操作符
						char cur_op = ops.top(); ops.pop();
						// 操作数 a, b
						int b = nums.top(); nums.pop();
						int a = nums.top(); nums.pop();
						int res = _cal(a, b, cur_op);
						nums.push(res);
					}
					ops.push(ch); // 当前 操作符入栈
				}
				else if (ch == ')') {
					// 计算括号内的表达式
					while (ops.top() != '(') {
						// 操作符
						char cur_op = ops.top(); ops.pop();
						// 操作数
						int b = nums.top(); nums.pop();
						int a = nums.top(); nums.pop();
						int res = _cal(a, b, cur_op);
						nums.push(res);
					}
					ops.pop(); // 弹出 '('
				}
				else {// * / (
					ops.push(ch);
				}
			}
			prev_ch = ch;
		}
		// 结尾的数字入栈
		if (cur_num != "") {
			nums.push(atoi(cur_num.c_str()));
			cur_num = "";
		}

		while (!ops.empty()) {
			char cur_op = ops.top(); ops.pop();
			// 操作数
			int b = nums.top(); nums.pop();
			int a = nums.top(); nums.pop();
			int res = _cal(a, b, cur_op);
			nums.push(res);
		}
		return nums.top();
	}
};