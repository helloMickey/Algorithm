// https://leetcode-cn.com/problems/linked-list-cycle-ii/comments/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr) {
            slow = slow->next;
            if (fast->next == nullptr) { // 不存在环
                return nullptr;
            }
            fast = fast->next->next;
            if (fast == slow) { // 相遇
                ListNode *ptr = head;
                while (ptr != slow) { // 寻找入环处
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};