// https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/

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
class Solution_Error {
public:
    TreeNode* _flatten(TreeNode* root){
        if(root->left == nullptr){

        }
        if(root->right == nullptr){

        }
        // 左子树单链
        TreeNode* node = flatten(root->left);
        // 右子树单链
        TreeNode* end_node = flatten(root->right);

        node->right = root->right;
        root->right = root->left;
        root->left = nullptr;
        
        return end_node; // 返回链末端的node
    }
    void flatten(TreeNode* root) {
        // 递归的过程

        
    }
};

class Solution_Native {
public:
    vector<TreeNode*> nodes;
    void _preOrder(TreeNode* root){
        if(root == nullptr){return;}
        nodes.push_back(root);
        _preOrder(root->left);
        _preOrder(root->right);
    }
    void flatten(TreeNode* root) {
        if(root == nullptr){return;}
        // 先序遍历，重新建链
        _preOrder(root);
        for(int i = 0; i < nodes.size() - 1; i++){
            nodes[i]->left = nullptr;
            nodes[i]->right = nodes[i+1];
        }
    }
};