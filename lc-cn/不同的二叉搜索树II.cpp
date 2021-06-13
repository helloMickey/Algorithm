// https://leetcode-cn.com/problems/unique-binary-search-trees-ii/

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
    //以当前区间能够构建的，所有可能的二叉搜索树
    vector<TreeNode*> generateTrees(int l, int u){
    // vector<TreeNode*>& generateTrees(int l, int u){  // 这里为什么函数返回不能是引用类型 ？？？？

        // l, u 区间的上下界
        if(l > u){
            return vector<TreeNode*>() = {nullptr};
            // return {nullptr};

        }
        if(l == u){
            TreeNode* node = new TreeNode(l, nullptr, nullptr);
            return vector<TreeNode*>() = {node};
            // return {node};

        }
        vector<TreeNode*> res;
        for(int i = l; i <= u; i++){
            vector<TreeNode*> all_left = generateTrees(l, i-1);

            vector<TreeNode*> all_right = generateTrees(i+1, u);
            
            for(auto l_p : all_left){
                for(auto r_p : all_right){
                    // 将cur_root 与左右子树关联起来
                    TreeNode* cur_root = new TreeNode(i, l_p, r_p);
                    // cur_root->left = l_p; 
                    // cur_root->right = r_p;
                    res.push_back(cur_root);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        // 这是一个递归的过程, 因为规定了树的类型是二叉搜索树，这也就是规定了左子树中的节点大小不能比右子树大
        return generateTrees(1, n);
    }
};