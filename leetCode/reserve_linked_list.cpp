struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (head == nullptr || head->next == nullptr) 
			return head;
		ListNode *cur, *pre , *r, *breakPoint, *rebuildPoint;
		
		ListNode *first = new ListNode(0); //set a affiliated head node
		first->next = head;
		//initial
		pre = first;
		cur = pre;
		int gap = n - m;

		while (m--) {
			pre = cur;
			cur = cur->next;
		}
		// cur point to node that 1th needed reserve
		breakPoint = pre; rebuildPoint = cur;
		r = cur->next;
		
		rebuildPoint->next = nullptr;//break the link

		while (gap--) {
			pre = cur;
			cur = r;
			r = cur->next;
			cur->next = pre; //reserve link
		}

		//relink
		breakPoint->next = cur;
		rebuildPoint->next = r;
		
		head = first->next;
		return head;//ignore the affiliated head node;
	}
	
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode* pre, *cur, *r;
		pre = head; cur = head; r = cur->next;
		while (r != nullptr) {
			pre = cur;
			cur = r;
			r = cur->next;

			cur->next = pre;
		}
		//cur->next = pre;
		head->next = nullptr;
		return cur;
	}
};
/*
int main() {
	ListNode* test = new ListNode(0);
	test->val = 1;

	test->next = new ListNode(0);
	test->next->val = 2;

	test->next->next = new ListNode(0);
	test->next->next->val = 3;

	test->next->next->next = new ListNode(0);
	test->next->next->next->val = 4;

	test->next->next->next->next = new ListNode(0);
	test->next->next->next->next->val = 5;

	Solution obj;
	obj.reverseList(test);
}
*/