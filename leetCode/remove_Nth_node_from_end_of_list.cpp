struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == nullptr || n == 0) return head;
		ListNode* current = head;
		int counter = 0;
		while (current != nullptr)
		{
			current = current->next;
			counter++;
		}
		int k = counter - n;
		ListNode* newHead = new ListNode(0);
		newHead->next = head;
		ListNode*pre = newHead;	
		current = head;
		while (k--) {
			pre = current;
			current = current->next;
		}
		//pre = current;
		pre->next = current->next;
		return newHead->next;
	}
};