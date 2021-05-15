// https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    vector<int> _inorder;
    vector<int> _postorder; 
    TreeNode* buildTree(int in_i, int in_j, int po_i, int po_j){
        // in_i, in_j 当前用于建树的节点值， 在vector中的下标索引
        
        if(in_i > in_j){ return nullptr;}
        if(in_i == in_j){ return new TreeNode(_inorder[in_i]);}

        // 递归
        TreeNode* cur_root = new TreeNode(_postorder[po_j]); // 后续遍历的最后一个元素
        int idx = std::find(_inorder.begin(), _inorder.end(), cur_root->val) - _inorder.begin(); // 获取下标位置
        
        int l_gap = idx - in_i; // 左右区间长度
        int r_gap = in_j - idx;
        // 根据root节点，将遍历序列一分为二
        cur_root->left = buildTree(in_i, in_i + l_gap - 1, po_i, po_i + l_gap - 1 ); // 注意区间的划分！！！
        cur_root->right = buildTree(in_j - r_gap + 1, in_j, po_j - r_gap , po_j - 1);
        
        return cur_root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // 这其中也包含一个递归的过程， 考虑如果划分为一个子问题
        _inorder = inorder;
        _postorder = postorder;
        
        return buildTree(0, _inorder.size()-1, 0, _postorder.size()-1);
    }
};