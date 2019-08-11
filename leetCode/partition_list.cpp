struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		if (head == nullptr) return nullptr;

		ListNode* low_list, *low_list_rear, *high_list, *high_list_rear, *cur;
		low_list = low_list_rear = new ListNode(0);//set affiliated head node
		high_list = high_list_rear = new ListNode(0);
		
		cur = head;
		while (cur != nullptr)
		{
			if (cur->val < x) {
				low_list_rear->next = cur;
				low_list_rear = cur;
			}
			else
			{
				high_list_rear->next = cur;
				high_list_rear = cur;
			}
			cur = cur->next;
		}
		high_list_rear->next = nullptr;//key!!!!!!!

		//ListNode* temp;
		//temp = high_list;
		low_list_rear->next = high_list->next;//link low_list anf high_list
		//delete temp;//delete affiliated head node
		//temp = low_list;
		low_list = low_list->next;
		//delete temp;
		return low_list;
	}
};