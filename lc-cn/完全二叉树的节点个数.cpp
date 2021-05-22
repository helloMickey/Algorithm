// https://leetcode-cn.com/problems/count-complete-tree-nodes/

/*
暴力方法，二叉树遍历记录节点个数。

优化方法：借助完全二叉树的特性，先确定完全二叉树深度为 h，那么最后一层的节点个数，通过二分法搜值确定。
当 0 < i < h 时，第 i 层包含 2^i 个节点，最底层包含的节点数最少为 1，最多为 2^h

对于一个完全二叉树而言，当节点从 1 开始编号时，要访问某个特定编号的节点时，例如 12 ，其对应的二进制值为 1100 ，
从二进制的第二位开始，1 代表向右，0 代表向右。所以访问次序应该时，右->左->左。
*/


// 优化方法：
// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/count-complete-tree-nodes/solution/wan-quan-er-cha-shu-de-jie-dian-ge-shu-by-leetco-2/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int level = 0;
        TreeNode* node = root;
        while (node->left != nullptr) { // 一直访问最左边叶子节点
            level++;
            node = node->left;
        }
        int low = 1 << level, high = (1 << (level + 1)) - 1; // 2^h ~ 2^(h+1) - 1
        while (low < high) { // 二分查找，确定最底层具体的个数
            int mid = (high - low + 1) / 2 + low;
            if (exists(root, level, mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }

    bool exists(TreeNode* root, int level, int k) {
        int bits = 1 << (level - 1);
        TreeNode* node = root;
        while (node != nullptr && bits > 0) {
            if (!(bits & k)) { // 确定下一步访问左子树还是右子树
                node = node->left;
            } else {
                node = node->right;
            }
            bits >>= 1;
        }
        return node != nullptr;
    }
};
