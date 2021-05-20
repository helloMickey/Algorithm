// https://leetcode-cn.com/problems/basic-calculator-ii/

/**
 * 最开始错误的思路是，判断为 + - 字符，对栈进行弹出计算表达式结果。 * / 字符则入栈。
 * / 的优先级要高于 *
 * 
 * 正确的思路是，符号栈是否进行弹出取决于当前操作符与栈顶操作符优先谁高，栈顶优先级高或者相等则先进行出栈和计算（相同优先级别，从左到右计算），直到栈顶元素优先机低于当前操作符
 * **/

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

	map<char, int> op_prior = {
		{'+', 1},
		{'-', 1},
		{'*', 3},
		{'/', 3},
	};
public:
	int calculate(string s) {
		// + -  字符，结果进行弹出, 对栈进行弹出计算表达式结果
		// * /  spc

		stack<int> nums;
		stack<char> ops;
		string cur_num = "";
		for (char ch : s) {
			if (ch >= '0' & ch <= '9') {
				cur_num += ch;
			}
			else {
				if (cur_num != "") {
					nums.push(atoi(cur_num.c_str())); // 数字入栈
					cur_num = "";
				}

				if (ch == ' ')
				{
					/* code */
				}
				else
				{
					while (!ops.empty()) {
						if (op_prior[ch] <= op_prior[ops.top()]) {
							// 当前操作符优先机小于栈顶元素
							// 弹出，进行表达式计算
							char cur_op = ops.top(); ops.pop();
							// 操作数
							int b = nums.top(); nums.pop();
							int a = nums.top(); nums.pop();
							int res = _cal(a, b, cur_op);
							nums.push(res);
						}
						else break;
					}
					ops.push(ch); // 当前操作符入栈
				}
			}
		}
		// 结尾的数字入栈
		if (cur_num != "") nums.push(atoi(cur_num.c_str()));

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