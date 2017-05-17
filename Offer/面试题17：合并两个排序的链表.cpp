/*
*
* 面试题17：合并两个排序的链表 
*
*/

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(nullptr) {}
};

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (!pHead1) {
		return pHead2;
	}
	if (!pHead2) {
		return pHead1;
	}
	ListNode *root = nullptr;
	ListNode *cur = nullptr;
	while (pHead1 != nullptr && pHead2 != nullptr){
		if (pHead1->val < pHead2->val) {
			if (root == nullptr) {
				root = cur = pHead1;
			}
			else {
				cur->next = pHead1;
				cur = cur->next;
			}
			pHead1	= pHead1->next;
		}else{
			if (root == nullptr) {
				root = cur = pHead2;
			}
			else {
				cur->next = pHead2;
				cur = cur->next;
			}
			pHead2 = pHead2->next;
		}
	}
	if (!pHead1) {
		cur->next = pHead2;
	}
	if (!pHead2) {
		cur->next = pHead1;
	}
	return root;
}

//递归版本
ListNode* merge_recursive(ListNode* pHead1, ListNode* pHead2)
{
	if (!pHead1) {
		return pHead2;
	}
	if (!pHead2) {
		return pHead1;
	}
	ListNode *root;
	if (pHead1->val < pHead2->val) {
		root = pHead1;
		root->next = merge_recursive(pHead1->next, pHead2);
	}
	else {
		root = pHead2;
		root->next = merge_recursive(pHead1, pHead2->next);
	}
	return root;
}