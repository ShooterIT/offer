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

//获得链表长度
unsigned int get_length(ListNode *head)
{
	unsigned int count = 0;
	//遍历一边链表
	while (head != nullptr){
		count++;
		head = head->next;
	}
	return count;
}

//查找第一个公共交点
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) 
{
	if (!pHead1 || !pHead2) {
		return nullptr;
	}
	//计算长度
	int length1 = get_length(pHead1);
	int length2 = get_length(pHead2);

	//计算两个链表长度，找出较长链表
	ListNode *longhead, *shorthead;
	if (length1 > length2) {
		longhead = pHead1;
		shorthead = pHead2;
	}
	else {
		longhead = pHead2;
		shorthead = pHead1;
	}
	//较长链表先走长度只差
	for (int i = 0; i < abs(length1 - length2); i++) {
		longhead = longhead->next;
	}
	//两个链表共同走，相等即第一个交点
	while (longhead && shorthead && longhead != shorthead){
		longhead = longhead->next;
		shorthead = shorthead->next;
	}
	//返回交点
	return longhead;
}