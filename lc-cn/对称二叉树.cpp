// https://leetcode-cn.com/problems/symmetric-tree/comments/

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
    bool isSymmetric(TreeNode* r1, TreeNode* r2){
        if(r1 == nullptr && r2 == nullptr){return true;}
        else if(r1 != nullptr && r2 != nullptr){
            return r1->val == r2->val && isSymmetric(r1->left, r2->right) && isSymmetric(r1->right, r2->left);
        }
        else{
            return false;
        }
    }
    bool isSymmetric(TreeNode* root) {
        // 之前用 python 写的对比遍历顺序的思路有问题

        // 这其实是一个递归问题
        
        // 判断一棵树是否是对称，当左右子树相互镜像时，该树是对称的
        // 要判断左右两个子树是否镜像，就是递归的去判断左树的右子树 和 右树的左子树 （判断两个树是否镜像），以及 左树的左子树 和 右树的右子树是否对称
        if(root == nullptr){
            return true;
        } else{
            return isSymmetric(root->left, root->rigth);
        }
    }
};