//using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == nullptr || headB == nullptr) return nullptr;
		int counter_A = 0;
		int counter_B = 0;
		ListNode* cur = headA;
		while (cur != nullptr) {
			cur = cur->next;
			counter_A++;
		}
		cur = headB;
		while (cur != nullptr) {
			cur = cur->next;
			counter_B++;
		}

		int k;
		ListNode* shortL;
		if (counter_A > counter_B) {
			k = counter_A - counter_B;
			cur = headA;
			shortL = headB;
		}
		else {
			k = counter_B - counter_A;
			cur = headB;
			shortL = headA;
		}
		//line up
		while (k--) {
			cur = cur->next;
		}
		while (cur != nullptr) {
			if (cur == shortL)
				return cur;
			else {
				cur = cur->next;
				shortL = shortL->next;	
			}
		}
		return nullptr;
	}
};