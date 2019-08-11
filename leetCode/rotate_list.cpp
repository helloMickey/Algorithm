
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (k == 0 || head == nullptr || head->next == nullptr) return head;

		ListNode* current = head;
		ListNode*pre = head;
		int counter = 0;
		while (current != nullptr)
		{
			pre = current;
			current = pre->next;
			counter++;
		}

		int k_r;
		if (k > counter)
			k_r = counter - k%counter;
		else if (k < counter)
			k_r = counter - k;
		else
			return head;
		
		current = head;
		while (--k_r)
		{
			current = current->next;
		}

		pre->next = head;//link the rear and head
		ListNode* newHead = current->next;
		current->next = nullptr;//break the link
		return newHead;
	}
};