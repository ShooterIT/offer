/*
*
* 面试题补4：删除链表中重复的结点
*
*/

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(nullptr) {}
};

ListNode* deleteDuplication(ListNode* pHead)
{
	if (!pHead || !pHead->next)
		return pHead;
	ListNode **cur = &pHead;
	while (*cur) {
		if ((*cur)->next && (*cur)->val == (*cur)->next->val) {
			int val = (*cur)->val; //重复值
			while ((*cur) && (*cur)->val == val) {
				ListNode * node = *cur;
				*cur = (*cur)->next;
				delete node;
				node = nullptr;
			}
		}
		else
			cur = &((*cur)->next);
	}
	return  pHead;
}