#include<vector>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty() || inorder.empty())
			return nullptr;
		return buildSubTree(preorder.begin(), preorder.end()-1, inorder.begin(), inorder.end()-1);
	}
	TreeNode* buildSubTree(vector<int>::iterator pre_l, vector<int>::iterator pre_h, vector<int>::iterator in_l, vector<int>::iterator in_h) {
		if (pre_l > pre_h || in_l > in_h)
			return nullptr;

		TreeNode* root = new TreeNode(*pre_l);//construct root node
		
		vector<int>::iterator median_in = in_l, median_pre = pre_l;
		while (*median_in != root->val && median_in <= in_h) {
			median_in++; median_pre++;
		}

		TreeNode* left = buildSubTree(pre_l + 1, median_pre, in_l, median_in-1);//left child tree
		TreeNode* right = buildSubTree(median_pre + 1, pre_h, median_in + 1, in_h);//right child tree

		root->left = left; 
		root->right = right;

		return root;
	}
	
	TreeNode* buildTree_2(vector<int>& inorder, vector<int>& postorder) {
		if (postorder.empty() || inorder.empty())
			return nullptr;
		return buildSubTree_2(postorder.begin(), postorder.end() - 1, inorder.begin(), inorder.end() - 1);
	}
	TreeNode* buildSubTree_2(vector<int>::iterator post_l, vector<int>::iterator post_h, vector<int>::iterator in_l, vector<int>::iterator in_h) {
		if (post_l > post_h || in_l > in_h)
			return nullptr;

		TreeNode* root = new TreeNode(*post_h);//construct root node

		vector<int>::iterator median_in = in_l, median_post = post_l;
		while (*median_in != root->val && median_in <= in_h) {
			median_in++; median_post++;
		}

		TreeNode* left = buildSubTree_2(post_l, median_post-1, in_l, median_in - 1);//left child tree
		TreeNode* right = buildSubTree_2(median_post + 1, post_h-1, median_in + 1, in_h);//right child tree

		root->left = left; root->right = right;
		return root;
	}

};
/*
int main() {
	vector<int> post(0), inord(0);

	post.push_back(3);
	post.push_back(2);
	//post.push_back(1);

	inord.push_back(2);
	//inord.push_back(1);
	inord.push_back(3);

	Solution obj;
	obj.buildTree_2(inord, post);
}
*/