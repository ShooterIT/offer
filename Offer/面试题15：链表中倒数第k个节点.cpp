/*
*
* 面试题15：链表中倒数第k个节点
* 输入一个链表，输出该链表中倒数第k个结点。
*
*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(nullptr) {}
};


ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) 
{
	//特殊值判断
	if (pListHead == nullptr || k == 0) {
		return nullptr;
	}
	ListNode* a = pListHead;
	ListNode* b = pListHead;

	//头指针先走k-1步，要判断是否链表长度是否小于k
	for (unsigned int i = 0; i < k - 1; i++) {
		if (a->next != nullptr) { //是否有后续节点
			a = a->next;
		}else{
			return nullptr;
		}
	}
	
	//寻找最后一个节点
	while (a->next != nullptr){
		a = a->next;
		b = b->next;
	}

	return b;
}

//中间节点
ListNode* find_middle(ListNode* pListHead)
{
	//一个快一个慢
	ListNode *slow = pListHead, *quick = pListHead;
	//快的走两步，慢的走一步
	while (quick && quick->next){
		slow = slow->next;
		quick = quick->next->next;
	}
	//慢的即为中间节点
	return slow;
}

/*
int main(void)
{
	ListNode *root = new ListNode(1);
	root->next = new ListNode(2);
	root->next->next = new ListNode(3);
	root->next->next->next = new ListNode(4);
	root->next->next->next->next = new ListNode(5);
	cout << find_middle(root)->val << endl;
	getchar();
	return 0;
}
*/