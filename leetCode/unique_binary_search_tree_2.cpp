#include<vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(0), left(nullptr), right(nullptr) {}
};

class Solution {	
public:
	vector<TreeNode*> generateTrees(int n) {
		vector<int> rootList;
		vector<TreeNode*> result;
		
		for (int i = 0; i < n; i++)
			rootList.push_back(i + 1);

		result = generateTree(rootList.begin(), rootList.end());

		return result;
	}
	vector<TreeNode*> generateTree(vector<int>::iterator low, vector<int>::iterator high) {
		vector<TreeNode*> result;
		if (low >= high) {
			result.push_back(nullptr);
			return result;
		}
		//else if (low == high) {
		//	result.push_back(new TreeNode(*low));
		//	return result;
		//}

		for (vector<int>::iterator cur_root = low; cur_root != high ; cur_root++) {
			//if(cur_root - 1 == 0)
			vector<TreeNode*> leftChild_set = generateTree(low, cur_root);
			vector<TreeNode*> rightChild_set = generateTree(cur_root + 1, high);

			for (vector<TreeNode*>::iterator it_l = leftChild_set.begin(); it_l != leftChild_set.end(); it_l++)
			{
				for (vector<TreeNode*>::iterator it_r = leftChild_set.begin(); it_r != leftChild_set.end(); it_r++)
				{
					TreeNode* tree = new TreeNode(*cur_root);
					tree->left = *it_l;
					tree->right = *it_r;
					result.push_back(tree);
				}
			}
		}
		return result;
	}
};
//
//int main() {
//	Solution obj;
//	obj.generateTrees(2);
//}