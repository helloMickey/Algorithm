#include<vector>
#include <iterator>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0)
			return nullptr;
		ListNode *currentList_1 = lists[0];
		ListNode *currentList_2;

		for (vector<ListNode*>::iterator it = lists.begin() + 1; it < lists.end(); it++) {
			currentList_2 = *it;

			ListNode * l1 = currentList_1; ListNode * l2 = currentList_2;
			ListNode *result = new ListNode(0), *current;//set head node
			current = result;
			int n1 = 0, n2 = 0;
			while (l1 != nullptr && l2 != nullptr)
			{
				n1 = l1->val;
				n2 = l2->val;

				if (n1 < n2) {
					//ListNode *temp = new ListNode(n1);
					//current->next = temp;
					//current = temp;
					current->next = l1;
					current = l1;
					l1 = l1->next;
				}
				else {
					//ListNode *temp = new ListNode(n2);
					//current->next = temp;
					//current = temp;
					current->next = l2;
					current = l2;
					l2 = l2->next;
				}
			}
			if (l1 == nullptr)
				current->next = l2;
			else if (l2 == nullptr)
				current->next = l1;

			current = result;
			result = result->next;//delete head
			delete current;
			currentList_1 = result;//medium result
		}
		return currentList_1;
	}
};