/*
*
* 面试题37：两个链表的第一个公共结点
*
*/

#include <cmath>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(nullptr) {
	}
};

unsigned int get_length(ListNode *head)
{
	unsigned int count = 0;
	while (head != nullptr){
		count++;
		head = head->next;
	}
	return count;
}

ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) 
{
	if (!pHead1 || !pHead2) {
		return nullptr;
	}

	int length1 = get_length(pHead1);
	int length2 = get_length(pHead2);

	ListNode *longhead, *shorthead;
	if (length1 > length2) {
		longhead = pHead1;
		shorthead = pHead2;
	}
	else {
		longhead = pHead2;
		shorthead = pHead1;
	}

	for (int i = 0; i < abs(length1 - length2); i++) {
		longhead = longhead->next;
	}

	while (longhead && shorthead && longhead != shorthead){
		longhead = longhead->next;
		shorthead = shorthead->next;
	}

	return longhead;
}