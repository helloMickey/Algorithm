// https://leetcode-cn.com/problems/palindrome-linked-list-lcci/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // 两步：1）快慢双指针遍历，找到链表中间节点；2) 慢指针遍历时，边遍历边反转。
        if(!head) return true;
        ListNode *p1 = head, *p2=head;
        ListNode *prev = nullptr;
        // int size = 0; // 记录节点总个数，需要知道是size是奇数还是偶数
        while(p2->next != nullptr && p2->next->next != nullptr){
            p2 = p2->next->next;    
        
            auto temp = p1;
            p1 = p1->next;
            temp->next = prev; // 对前半部分进行反转
            prev = temp;
        }
        if(p2->next == nullptr){// 奇数个节点，此时 p1 指向中间节点
            p1 = p1->next; // 前进一步
            p2 = prev;
        }else{ // 偶数个节点, p1 指向中间的左侧
            p2 = p1->next;
            p1->next = prev;
        }
        while(p2!= nullptr && p1 != nullptr){
            if(p2->val != p1->val) return false;
            p2 = p2->next;
            p1 = p1->next;
        }
        return true;
    }
};