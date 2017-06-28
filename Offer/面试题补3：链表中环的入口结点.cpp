/*
*
* 面试题补3：链表中环的入口结点
* 一个链表中包含环，请找出该链表的环的入口结点。
*
*/

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(nullptr) {}
};

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	//头不能为空，且有头的下一个节点也不为空
	if (!pHead || !pHead->next) {
		return nullptr;
	}

	ListNode *slow = pHead->next; //慢指针
	ListNode *quick = pHead->next->next;//快指针

	//在环中相遇,快走两步，慢走一步
	while (quick && quick->next && slow != quick) {
		slow = slow->next;
		quick = quick->next->next;
	}
	if (slow != quick) {
		return nullptr;
	}
	//寻找入环节点
	quick = pHead;
	while (quick != slow) {
		quick = quick->next;
		slow = slow->next;
	}
	return slow;
}