/**
* Your MyStack object will be instantiated and called as such:
* MyStack obj = new MyStack();
* obj.push(x);
* int param_2 = obj.pop();
* int param_3 = obj.top();
* bool param_4 = obj.empty();
*/
#include <queue>
using namespace std;
class MyStack {
private:
	queue<int> data;
public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		data.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		queue<int> temp;
		while (data.size() > 1)
		{
			int val = data.front();
			data.pop(); 
			temp.push(val);
		}
		int ret = data.front(); 
		data.pop();
		data = temp;
		return ret;
	}

	/** Get the top element. */
	int top() {
		queue<int> temp;
		while (data.size() > 1)
		{
			int val = data.front();
			data.pop();
			temp.push(val);
		}
		int ret = data.front();data.pop();
		temp.push(ret);
		data = temp;
		return ret;
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		if (data.empty())
			return true;
		else
			return false;
	}
};

