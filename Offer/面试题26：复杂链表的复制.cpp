/*
*
* 面试题26：复杂链表的复制
*
*/

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(nullptr), random(nullptr) {}
};

void clone_node(RandomListNode *phead)
{
	while (phead != nullptr) {
		RandomListNode * pclone = new RandomListNode(phead->label);
		pclone->next = phead->next;
		phead->next = pclone;
		phead = pclone->next;
	}
}

void connect_sibling(RandomListNode *phead)
{
	while (phead != nullptr) {
		if (phead->random != nullptr) {
			phead->next->random = phead->random->next;
		}
		phead = phead->next->next;
	}
}


RandomListNode *cut(RandomListNode *phead)
{
	RandomListNode *newclone = phead->next;
	while (phead != nullptr) {
		RandomListNode *clone = phead->next;
		phead->next = clone->next;
		phead = phead->next;
		if (phead) {
			clone->next = phead->next;
		}
		else {
			clone->next = nullptr;
		}
	}
	return newclone;
}

RandomListNode* Clone(RandomListNode* pHead)
{
	if (pHead == nullptr) {
		return nullptr;
	}

	clone_node(pHead);
	connect_sibling(pHead);
	return cut(pHead);
}
