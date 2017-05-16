/*
*
* 面试题15：链表中倒数第k个节点
*
*/


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(nullptr) {}
};


ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) 
{
	if (pListHead == nullptr || k == 0) {
		return nullptr;
	}
	ListNode* a = pListHead;
	ListNode* b = pListHead;

	for (unsigned int i = 0; i < k - 1; i++) {
		if (a->next != nullptr) {
			a = a->next;
		}else{
			return nullptr;
		}
	}
	
	while (a->next != nullptr){
		a = a->next;
		b = b->next;
	}

	return b;
}