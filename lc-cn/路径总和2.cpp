// https://leetcode-cn.com/problems/path-sum-ii/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> cur_path;
    vector<vector<int> > res;

    void pathSumRec(TreeNode* root, int remain){
        if(root == nullptr){return;}

        // 访问到叶子节点时进行判定
        cur_path.push_back(root->val);
        
        if(root->left == nullptr && root->right == nullptr){
            if(root->val == remain){
                res.push_back(cur_path); // 记录一条完成路径
            }
            cur_path.pop_back();
            return;
        }
        pathSumRec(root->left, remain - root->val);
        pathSumRec(root->right, remain - root->val);

        cur_path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        pathSumRec(root, targetSum);
        return res;
    }
};