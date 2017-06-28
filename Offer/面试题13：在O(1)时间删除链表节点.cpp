/*
*
* 面试题13：在O(1)时间删除链表节点
*
*/

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(nullptr) {
	}
};

void delete_node(ListNode **head, ListNode *delete_node)
{
	//特殊情况判断
	if (!head || !*head || !delete_node) {
		return;
	}

	//如果有后续节点，拷贝下一个节点内容，并将其删除
	if (delete_node->next != nullptr) {
		ListNode *node = delete_node->next;
		delete_node->val = node->val;
		delete_node->next = node->next;
		delete node;
		node == nullptr;
	}
	//删除对应节点
	else {
		//查找相应的点
		while (*head != delete_node) {
			head = &((*head)->next);
		}
		//修改
		*head = (*head)->next;
		delete delete_node;
		delete_node = nullptr;
	}
}