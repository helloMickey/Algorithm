// https://leetcode-cn.com/problems/leaf-similar-trees/

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
    vector<int> v1;
    vector<int> v2;
    void inOrdTrv(TreeNode* root, vector<int>& val){
        if(root->left == nullptr && root->right == nullptr){
            val.push_back(root->val);
            return;
        }
        if(root->left != nullptr){
            inOrdTrv(root->left, val);
        }
        if(root->right != nullptr){
            inOrdTrv(root->right, val);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        // 中序或先序遍历，访问所有叶节点
        inOrdTrv(root1, v1);
        inOrdTrv(root2, v2);

        if(v1.size() != v2.size()){return false;}
        else{
            for(int i = 0; i < v1.size(); i++){
                if(v1[i] != v2[i]){return false;}
            }
        }
        return true;
    }
};