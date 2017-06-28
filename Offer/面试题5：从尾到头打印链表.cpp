/*
*
* 面试题5：从尾到头打印链表
* 输入一个链表，从尾到头打印链表每个节点的值。
*
*/

#include <vector>
#include <stack>

using std::stack;
using std::vector;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(nullptr) {
	}
};

//插入
void insert(ListNode **head, int value)
{
	ListNode *new_node = new ListNode(value);
	if (*head == nullptr) {
		*head = new_node;
	}
	else {
		ListNode *n = *head;
		while (n->next != nullptr){
			n = n->next;
		}
		n->next = new_node;
	}
}

//删除
void remove(ListNode **head, int value)
{
	if (head == nullptr || *head == nullptr) {
		return;
	}

	ListNode *delete_node = nullptr;
	
	//头节点的特殊处理
	if ((*head)->val == value) {
		delete_node = *head;
		*head = (*head)->next;
	}
	else {
		ListNode *n = *head;
		//遍历寻找
		while (n->next != nullptr && n->next->val != value){
			n = n->next;
		}
		if (n->next != nullptr && n->next->val != value) {
			delete_node = n->next;
			n->next = n->next->next;
		}
	}
	if (delete_node != nullptr) {
		delete delete_node;
		delete_node = nullptr;
	}
}

//从头到尾打印
vector<int> printListFromTailToHead(ListNode* head) 
{
	//用一个栈进行存，保证逆序
	stack<int> si;
	while (head != nullptr) {
		si.push(head->val);
		head = head->next;
	}
	//输出到vector里
	vector<int> vi;
	while (!si.empty()) {
		vi.push_back(si.top());
		si.pop();
	}
	return vi;
}
vector<int> printListFromTailToHead2(ListNode* head)
{
	vector<int> vi;
	printListFromTailToHead3(vi, head);
	return vi;
}

//递归打印
void printListFromTailToHead3(vector<int> &vi, ListNode* head)
{
	if (head != nullptr) {
		//未到尾部就继续
		if (head->next != nullptr) {
			printListFromTailToHead3(vi,head->next);
		}
		vi.push_back(head->val);
	}
}