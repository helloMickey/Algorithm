// https://leetcode-cn.com/problems/copy-list-with-random-pointer/
/*
方法一：
      这里关键要知道 random 指向的节点是链中的第几个元素。 
      第一遍，遍历构建链，map 记录原始节点的地址，和新建链的地址的对应关系。
      第二遍，为新链表每个节点的 random 赋值
      map 的访问时间为 O(1)
方法二：优化方法
原地克隆并，进行分裂！！！！
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* ite = head;
        while (ite) { // 用next连接
            Node* n = new Node(ite->val, ite->next, nullptr);
            Node* c = ite->next;
            ite->next = n;
            ite = c;
        }
        ite = head;
        while (ite) { // 连接random
            if (ite->random) ite->next->random = ite->random->next;
            ite = ite->next->next;
        }
        ite = head;
        Node* ret = head->next;
        while (ite->next) { // 有丝分裂(大雾)
            Node* c = ite->next;
            ite->next = ite->next->next;
            ite = c;
        }
        return ret;
    }
};