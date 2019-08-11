#include <vector>
#include<stack>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
	 TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//recursice version
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result(0);
		inorderTraversal(root, result);
		return result;
	}
	void inorderTraversal(TreeNode* root, vector<int> &storage) {
		if (root == NULL) {
			return;
		}
		inorderTraversal(root->left, storage);
		storage.push_back(root->val);
		inorderTraversal(root->right, storage);
	}
};
class Solution_iterative
{
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> traversal_stack;
		TreeNode* currentRoot = root;
		while (!traversal_stack.empty() || currentRoot!= NULL)
		{
			while (currentRoot != NULL)
			{
				traversal_stack.push(currentRoot);
				currentRoot = currentRoot->left;
			}
			currentRoot = traversal_stack.top();traversal_stack.pop();
			result.push_back(currentRoot->val); 
			currentRoot = currentRoot->right;
		}
		return result;
	}
};