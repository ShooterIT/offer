/*
*
* 面试题17：合并两个排序的链表 
* 输入两个单调递增的链表，输出两个链表合成后的链表，
* 当然我们需要合成后的链表满足单调不减规则。
*
*/

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(nullptr) {}
};

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	//判断特殊输入
	if (!pHead1) {
		return pHead2;
	}
	if (!pHead2) {
		return pHead1;
	}
	ListNode *root = nullptr;
	ListNode *cur = nullptr;
	//一直继续，直到两个链表有一个为空
	while (pHead1 != nullptr && pHead2 != nullptr){
		if (pHead1->val < pHead2->val) {
			//起始点的判断
			if (root == nullptr) {
				root = cur = pHead1;
			}
			else {
				//迭代
				cur->next = pHead1;
				cur = cur->next;
			}
			pHead1	= pHead1->next; //小的链表后移
		}else{
			//起始点的判断
			if (root == nullptr) {
				root = cur = pHead2;
			}
			else {
				//迭代
				cur->next = pHead2;
				cur = cur->next;
			}
			pHead2 = pHead2->next; //小的链表后移
		}
	}
	//剩余部分
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
	//一个链表为空，则剩余部分为另一个链表
	if (!pHead1) {
		return pHead2;
	}
	if (!pHead2) {
		return pHead1;
	}
	//根据大小设置头结点，剩余部分使用递归
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

