// https://leetcode-cn.com/problems/longest-univalue-path/

class Solution {
    // 思路类似与 二叉树的最大路径和 ~
public:
    int path;
    int longestPath(TreeNode* curr)
    {
        if(!curr) return 0;

        // 路径递归
        // left  ，以 curr->left 为父节点的，最长同值路径长度
        int left = longestPath(curr->left);
        int right = longestPath(curr->right);

        // 路径计算
        // left  计算 curr 为始的左侧 最长同值路径长度
        // right 计算 curr 为始的右侧 最长同值路径长度
        // cur_path  计算 curr 为根的全树 最长同值路径长度
        left = (curr->left && curr->left->val == curr->val) ? (left + 1) : 0;
        right = (curr->right && curr->right->val == curr->val) ? (right + 1) : 0;
        int cur_path = left + right

        path = max(path, cur_path); // 更新最大路径

        // 取以 curr 节点为始的左右侧 最长同值路径长度 的最大值
        return max(left, right);
    }

    int longestUnivaluePath(TreeNode* root) {
        longestPath(root);
        return path;
    }
};