/*
*
* 面试题补5：二叉树的下一个结点
* 给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
* 注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
*
*/

//树的定义
struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(nullptr), right(nullptr), next(nullptr) {}
};


TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
	//特殊值判读
	if (pNode == nullptr) {
		return nullptr;
	}
	//有右节点
	if (pNode->right != nullptr) {
		TreeLinkNode *root = pNode->right;
		while (root->left != nullptr) {
			root = root->left;
		}
		return root;
	}
	//没有右节点,当往上查找时，此条路径的节点是某个根节点的左节点时
	//那么该根节点就是要查找节点的下一个节点。
	TreeLinkNode *node = pNode->next;
	while (node != nullptr && pNode != node->left) {
		pNode = node;
		node = pNode->next;
	}

	return node;
}