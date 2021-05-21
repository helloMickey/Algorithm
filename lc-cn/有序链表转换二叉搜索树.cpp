// https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/

// 方法1：先 BFS 建立一个平衡二叉树，再 中序遍历 过程中遍历链表将链表值填充进去；
// 方法2：先遍历链表，取出所有节点值，直接分治构建二叉平衡树；
// 方法2改进：用快慢指针直接找出中点元素；好处是无需进行链表的遍历！！！
// 用两个指针，一块一慢，快的每次走两步，慢的每次走一步，这样当快指针遍历结束时，慢指针指向的也就是链表的中间位置。

class Solution {
public:
    ListNode* getMedian(ListNode* left, ListNode* right) {
        ListNode* fast = left;
        ListNode* slow = left;
        while (fast != right && fast->next != right) {
            fast = fast->next;
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }

    TreeNode* buildTree(ListNode* left, ListNode* right) {
        if (left == right) {
            return nullptr;
        }
        ListNode* mid = getMedian(left, right);
        TreeNode* root = new TreeNode(mid->val);
        root->left = buildTree(left, mid);
        root->right = buildTree(mid->next, right);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        return buildTree(head, nullptr);
    }
};