/*
*
* 面试题16：反转链表
* 题目：定义一个函数，输入链表的头结点，反转链表，并返回反转后链表的头结点
* 思路：pre cur next上个指针，pre记录前一个，cur为当前，
* next记录下一个（为了防止更改next时链表断开）
*
*/

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(nullptr) {}
};

ListNode* ReverseList(ListNode* pHead) 
{
	ListNode *pre = nullptr;
	//不为空，就继续反转
	while (pHead != nullptr) {
		ListNode *next = pHead->next; //记录下一个位置
		pHead->next = pre; //当前位置反转
		pre = pHead;       //跟新pre和当前位置
		pHead = next;
	}
	return pre;
}