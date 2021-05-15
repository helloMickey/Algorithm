// https://leetcode-cn.com/problems/binary-tree-level-order-traversal/submissions/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(!root){ return res; }
        deque<TreeNode*> trv_nodes;
        trv_nodes.push_back(root);
        int i_counter = 1; // 当前层节点数目
        while(!trv_nodes.empty()){
            int next_counter = 0; // 下一层的节点个数
            vector<int> i_layer_nodes = {};
            while(i_counter--){
                auto node = trv_nodes.front();
                trv_nodes.pop_front();
                i_layer_nodes.push_back(node->val);
                if(node->left != nullptr){
                    trv_nodes.push_back(node->left);
                    next_counter++;
                }
                if(node->right != nullptr){
                    trv_nodes.push_back(node->right);
                    next_counter++;
                }
            }
            res.push_back(i_layer_nodes);
            i_counter = next_counter;
        }
        return res;
    }
};