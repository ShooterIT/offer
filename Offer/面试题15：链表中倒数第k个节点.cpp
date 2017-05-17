/*
*
* 面试题15：链表中倒数第k个节点
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

//中间节点
ListNode* find_middle(ListNode* pListHead)
{
	ListNode *slow = pListHead, *quick = pListHead;
	while (quick && quick->next){
		slow = slow->next;
		quick = quick->next->next;
	}
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