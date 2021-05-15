// https://leetcode-cn.com/problems/recover-binary-search-tree/

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
    vector<int> vals;
    int idx = 0;
    void recoverTree(TreeNode* root) {
        // 进行节点交换时，交换 val，这样树结构就不会对树结构造成影响
        // 我们不必去记录每个val值所对应的节点指针，只需知道正确值应该是多少
        inorderTrv(root);

        std::sort(vals.begin(), vals.end());

        inorderTrvSet(root);
    }
    void inorderTrv(TreeNode* root){ // 中序遍历获取值
        if(root == nullptr){return;}
        inorderTrv(root->left);
        vals.push_back(root->val);
        inorderTrv(root->right);
    }
    void inorderTrvSet(TreeNode* root){
        if(root == nullptr){return;}
        inorderTrvSet(root->left);
        root->val = vals[idx++];
        inorderTrvSet(root->right);
    }
};