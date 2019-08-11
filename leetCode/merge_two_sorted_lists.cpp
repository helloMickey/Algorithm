struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *result = new ListNode(0), *current;//set head node
		current = result;
		int n1 = 0, n2 = 0;
		while (l1!=nullptr && l2!=nullptr)
		{
			n1 = l1->val;
			n2 = l2 ->val;
			
			if (n1 < n2) {
				ListNode *temp = new ListNode(n1);
				current->next = temp;
				current = temp;
				l1 = l1->next;
			}
			else{
				ListNode *temp = new ListNode(n2);
				current->next = temp;
				current = temp;
				l2 = l2->next;
			}
		}
		if (l1 == nullptr)
			current->next = l2;
		else if (l2 == nullptr)
			current->next = l1;
	/*	while (l1 != nullptr)
		{
			n1 = l1->val;
			ListNode *temp = new ListNode(n1);
			current->next = temp;
			current = temp;
			l1 = l1->next;
		}
		while(l2 != nullptr)
		{
			n2 = l2->val;
			ListNode *temp = new ListNode(n2);
			current->next = temp;
			current = temp;
			l2 = l2->next;
		}*/
		current = result;
		result = result->next;//delete head
		delete current;
		return result;
	}
};