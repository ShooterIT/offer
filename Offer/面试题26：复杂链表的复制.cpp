/*
*
* 面试题26：复杂链表的复制
* 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，
* 另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
* （注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
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

RandomListNode* Clone(RandomListNode* pHead)
{
	if (pHead == nullptr) {
		return nullptr;
	}

	//复制
	RandomListNode *node = pHead;
	while (node != nullptr){
		RandomListNode *tmp = new RandomListNode(node->label);
		tmp->next = node->next;
		node->next = tmp;
		node = tmp->next;
	}
	//拷贝random域
	node = pHead;
	while (node != nullptr) {
		if (node->random != nullptr) {
			node->next->random = node->random->next;
		}
		node = node->next->next;
	}
	//新链表从原链表中断开
	node = pHead;
	RandomListNode *root = pHead->next;
	while (node->next != nullptr) {
		RandomListNode *tmp = node->next;
		node->next = tmp->next;
		node = tmp;
	}
	return root;
}
