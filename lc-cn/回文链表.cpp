// https://leetcode-cn.com/problems/palindrome-linked-list/

// 快慢指针

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) {
            return true;
        }

        // 找到前半部分链表的尾节点并反转后半部分链表
        ListNode* firstHalfEnd = endOfFirstHalf(head);
        ListNode* secondHalfStart = reverseList(firstHalfEnd->next);

        // 判断是否回文
        ListNode* p1 = head;
        ListNode* p2 = secondHalfStart;
        bool result = true;
        while (result && p2 != nullptr) {
            if (p1->val != p2->val) {
                result = false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }        

        // 还原链表并返回结果
        firstHalfEnd->next = reverseList(secondHalfStart);
        return result;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    ListNode* endOfFirstHalf(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        // 在快慢指针中，这里的判断条件是有讲究的，看实际是要中间的哪一个节点（1 2 2 1， 中要第一个2还是第二个2）
        while (fast->next != nullptr && fast->next->next != nullptr) { 
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};

class Solution_error {
    // 这个解法存在问题，忘记继续进行链表反转
public:
    bool isPalindrome(ListNode* head) {
        // 关键在于找到链表中的中间的一个节点
        ListNode *p1 = head, *p2 = head;
        while(p2 != nullptr && p2->next != nullptr){
            p1 = p1->next;            
            p2 = p2->next->next;
        }
        // p1 当前指向链表中间的节点（注意，我们的需求是，当链表为 1 2 2 1 时 p1 指向 第二个 2）
        // cout << p1->val << endl;
        ListNode* cur = prev_p;
        while(cur != p1 && p1 != nullptr){
            cout <<p1->val << endl;
            if(cur->val != p1->val) return false;
            cur = cur->next;
            p1 = p1->next;
        }
        return false;        
    }
};