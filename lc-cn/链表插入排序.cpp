// https://leetcode-cn.com/problems/insertion-sort-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return head;

        ListNode* prev = new ListNode(-1, nullptr); // 最终有序的结果链
        ListNode* remain_head = head;
        // 遍历每一个元素，然后插入至合适位置
        while(remain_head){
            ListNode* cur_node = remain_head;
            remain_head = cur_node->next;

            ListNode* temp = prev->next, *temp_prev = prev;
            while(temp && temp->val < cur_node->val){ // 寻找插入位置
                temp_prev = temp;
                temp = temp->next;
            }

            if(!temp){
                // 当前节点比所有的都要大，那么插入尾部即可
                temp_prev->next = cur_node;
                cur_node->next = nullptr; // 最终有序链的末尾指向null
            }else{
                // 当前节点插入在中间
                temp_prev->next = cur_node;
                cur_node->next = temp;
            }
            
        }
        return prev->next;
    }
};