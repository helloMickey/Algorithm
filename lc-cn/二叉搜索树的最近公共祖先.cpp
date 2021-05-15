// https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr){ return nullptr;}
        // 要充分利用二叉搜索树的性质
        if(root->val > p->val && root->val > q->val){
            // 左子树遍历
            return lowestCommonAncestor(root->left, p, q);
        }
        if(root->val < p->val && root->val < q->val){
            // 右子树遍历
            return lowestCommonAncestor(root->right, p, q);
        }
        return root; // p, q 位于 root 两侧
    }
};