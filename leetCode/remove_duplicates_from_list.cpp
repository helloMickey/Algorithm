#include <set>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	//如果当前节点前面已经出现过，则删除
	/*
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr) return nullptr;
		set<int> S;
		S.insert(head->val);
		ListNode* cur = head->next, *pre = head;
		while (cur != nullptr)
		{
			if (S.find(cur->val) != S.end()) {//find cur->val
				pre->next = cur->next;
				delete cur;
				cur = pre;
			}
			else {
				S.insert(cur->val);
				pre = cur;
			}
			cur = cur->next;
		}
		return head;
	}
	*/
	//删除出现过不止一次的节点
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr ) return nullptr;
		set<int> S1, S2;
		S1.insert(head->val);
		ListNode* cur = head->next, *pre = head;
		while (cur != nullptr)
		{
			if (S1.find(cur->val) != S1.end()) //find cur->val in S1
				S2.insert(cur->val);
			else
				S1.insert(cur->val);
			cur = cur->next;
		}
		ListNode* front = new ListNode(0);
		front->next = head;
		cur = head; pre = front;
		while (cur != nullptr)
		{
			if (S2.find(cur->val) != S2.end()) {//find cur->val in S2
				pre->next = cur->next;
				delete cur;
				cur = pre;
			}
			pre = cur;
			cur = cur->next;
		}
		return front->next;
	}
};