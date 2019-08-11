#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> result;
		if (root == nullptr)
		{
			result.clear();
			return result;
		}
		queue<TreeNode*> q; q.push(root);
		int len = 1;
		bool turn = false;
		vector<int> line;
		
		//��������
		while (!q.empty())
		{
			TreeNode *cur = q.front(); q.pop();
			len--;
			line.push_back(cur->val);

			if (cur->left != nullptr)
				q.push(cur->left);//һ��Ҫ��ڵ��Ƚ�
			if (cur->right != nullptr)
				q.push(cur->right);

			if (len == 0) {//��ʾһ��������
				len = q.size(); //��ǰqueue�н�����Ŀ��ʾ��һ��ڵ����

				if (turn)//��ת
					reverse(line.begin(), line.end());
				 
				turn = !turn;//turn��ֵȡ������ʾ��һ�㲻�÷�ת

				result.push_back(line);
				line.clear();
			}

		}
		return result;
	}
};
//int main(){
//	Solution obj;
//}