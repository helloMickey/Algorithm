// https://leetcode-cn.com/problems/convert-bst-to-greater-tree/

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
class Solution { // 典型的中序遍历（但是左右子树中，先访问右子树）
    
    int sum = 0; // 累计值
    void midTrv(TreeNode* root){
        // 中序遍历，先访问右子树
        if(root == nullptr) return ;
        
        midTrv(root->right);
        
        sum += root->val;
        root->val = sum; 
        
        midTrv(root->left);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        midTrv(root);
        return root;
    }
};