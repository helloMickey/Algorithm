// https://leetcode-cn.com/problems/intersection-of-two-linked-lists-lcci/

/*
两种方法：
1）双指针先找到长链比短链多的 K 个节点。
然后两个链同步遍历，查看是否存在相同节点。

2）将第一个链表连到第二个链表尾部，就是一个判断一个链表是否有环的题目
在返回结果后，两个链表仍须保持原有的结构。
*/

class Solution { // 方法2
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *h1 = headA, *h2 = headB;

        while (h1 != h2) {

            h1 = h1 == nullptr ? headB : h1.next;
            h2 = h2 == nullptr ? headA : h2.next;
        }

        return h1;  
      
    }
};