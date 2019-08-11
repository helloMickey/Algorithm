//#include <math.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

//class Solution {
//public:
//	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//		ListNode* result;
//		int n1 = 0, n2 = 0;
//		int count1 = 0, count2 = 0;
//		while (l1 != nullptr)
//		{
//			int data = l1->val;
//			n1 += data * ::pow(10, count1++);
//			l1 = l1->next;
//		}
//		while (l2 != nullptr)
//		{
//			int data = l2->val;
//			n2 += data * ::pow(10, count2++);
//			l2 = l2->next;
//		}
//		int sum = n1 + n2;
//
//		double flag = 0;
//		int data = sum % 10;
//		flag = sum / 10; sum = sum / 10;
//		result = new ListNode(data);
//
//		ListNode* current = result;
//		while (flag >= 1)
//		{
//			data = sum % 10;
//			flag = sum / 10; sum = sum / 10;
//			ListNode *temp = new ListNode(data);
//			current->next = temp;
//			current = temp;
//		}
//		return result;
//	}
//};
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* result;
		int crray_bit = 0;//carry digit
		result = new ListNode(0);//set head node
		ListNode* current = result;
		while (l1 != nullptr && l2 != nullptr)
		{
			int data1 = l1->val;
			int data2 = l2->val;
			int sum = data1 + data2 + crray_bit;

			ListNode *temp = new ListNode(sum%10);
			current->next = temp;
			current = temp;

			crray_bit = sum >= 10 ? 1 : 0;

			l1 = l1->next; 	l2 = l2->next;
		}
		while (l1 != nullptr)
		{
			int data1 = l1->val;
			int sum = data1 + crray_bit;
			ListNode *temp = new ListNode(sum % 10);
			crray_bit = sum >= 10 ? 1 : 0;
			current->next = temp;
			current = temp;
			l1 = l1->next;
		}
		while (l2 != nullptr)
		{
			int data2 = l2->val;
			int sum = data2 + crray_bit;
			ListNode *temp = new ListNode(sum % 10);
			crray_bit = sum >= 10 ? 1 : 0;
			current->next = temp;
			current = temp;
			l2 = l2->next;
		}
		if (crray_bit != 0)
		{
			ListNode *temp = new ListNode(crray_bit);
			current->next = temp;
		}
		current = result;
		result = result->next;
		delete current;//delete head node
		return result;
	}
};