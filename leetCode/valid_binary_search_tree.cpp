#include <vector>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		if (root == NULL)
			return true;
		//get the first node's value of inorder traversal
		//TreeNode* first = root;
		//while (first -> left != NULL)
		//	first = first->left;
		//let the pre_value's initial value less than first_node's value 
		//int pre_first = first->val - 1;
		int pre_value;
		bool is_first_node = true;
		return isValidBST(root, pre_value, is_first_node);
	}
	bool isValidBST(TreeNode* root, int& pre_value, bool& is_first_node) {
		if (root == NULL)
			return true;
		
		if (!isValidBST(root->left, pre_value, is_first_node))
			return false;

		//visit
		if (is_first_node)
		{
			is_first_node = false;
			pre_value = root->val;
		}
		else if (root->val <= pre_value)
			return false;
		else pre_value = root->val;

		if (!isValidBST(root->right, pre_value, is_first_node))
			return false;

		return true;
	}
	/*
	bool isvalidbst(treenode* root, int& value) {
		if (root == null)
			return true;
		value = root->val;

		int root_val_l = root->val - 1; //if left_child if null, the root_val_l's value will not cause a error;
		bool flag_l = isvalidbst(root->left, root_val_l);

		int root_val_r = root->val + 1;
		bool flag_r = isvalidbst(root->right, root_val_r);
		
		bool flag_m;
		if (root->val > root_val_l && root->val < root_val_r)
			flag_m = true;
		else flag_m = false;

		return (flag_l && flag_r && flag_m);
	}
	*/
};