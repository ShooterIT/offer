/*
*
* 面试题16：反转链表
*
*/

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(nullptr) {}
};

ListNode* ReverseList(ListNode* pHead) 
{
	ListNode *head = pHead;
	ListNode *node = pHead;
	ListNode *pre = nullptr;
	while (node != nullptr) {
		ListNode *next = node->next;
		if (next == nullptr) {
			head = node;
		}
		node->next = pre;
		pre = node;
		node = next;
	}
	return head;
}