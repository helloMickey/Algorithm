//using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	void recoverTree(TreeNode* root) {
		//递归进行解决，

	}
	void recoverTree(TreeNode* root, TreeNode* pre_illNode) {
		if (root == nullptr)
			return;

		TreeNode* pre_ill_1;
		recoverTree(root->left, pre_ill_1);

		TreeNode* pre_ill_2;
		recoverTree(root->right, pre_ill_2);

		if (pre_ill_1 != nullptr && pre_ill_2 != nullptr)
		{
			//recover
			TreeNode* temp = pre_ill_1;
			//pre_ill_1->
		}
	}
};