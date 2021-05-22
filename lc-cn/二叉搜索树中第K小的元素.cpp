// https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/

/*
方法1：中序遍历，记录遍历结果，第 k 个记录中即为最终所需结果；

方法2：通过迭代，对树进行中序遍历，好处在于，当查找到第 K 小的元素时可以终止迭代过程，而无需完成整个遍历。
*/

class Solution {
public:
    stack<TreeNode*> inorderTrvStack; // 栈顶永远存放下一个要访问的元素
    int kthSmallest(TreeNode* root, int k) {
        int counter = 0;
        // 右子树先入栈，左子树后入栈

        inorderTrvStack.push(root);
        auto cur_p = root->left;
        // 最左节点入栈
        while(cur_p != nullptr){
            inorderTrvStack.push(cur_p);
            cur_p=cur_p->left;
        }

        while (!inorderTrvStack.empty())
        {
            TreeNode* cur = inorderTrvStack.top(); inorderTrvStack.pop(); // 他的左节点一定都访问过了
            counter ++;
            if(counter == k) return cur->val;

            if(cur->right != nullptr){
                inorderTrvStack.push(cur->right);
                auto cur_p = cur->right->left;
                // 最左节点入栈
                while(cur_p != nullptr){
                    inorderTrvStack.push(cur_p);
                    cur_p=cur_p->left;
                }       
            }
        }
        return 0;
    }
};