// https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/

/*
思路：
    当两个链表等长时，遍历第一次相遇时，便是第一个公共节点
    不等长时，需要将两者调至距离公共节点等距离的位置 !!!!!
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA, *p2 = headB;
        while(p1 != nullptr && p2 != nullptr){
            p1 = p1->next;
            p2 = p2->next;
        }
        ListNode *l_p, *s_p,*con_p;
        if(p1 == nullptr){
            l_p = headB; s_p = headA; con_p = p2;
        }else{
            l_p = headA; s_p = headB; con_p = p1;
        }

        while(con_p != nullptr){
            con_p = con_p->next;
            l_p = l_p->next;    
        }

        // 现在 l_p 和 s_p 对齐了
        while(l_p != nullptr && s_p != nullptr){
            if(l_p == s_p) return l_p; // 可能在开头就相交
            l_p = l_p->next;
            s_p = s_p->next;
        }
        return nullptr; // 不相交 
    }
};