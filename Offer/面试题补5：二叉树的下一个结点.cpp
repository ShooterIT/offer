/*
*
* 面试题补5：二叉树的下一个结点
*
*/

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
	if (!pNode) {
		return nullptr;
	}
	TreeLinkNode *next = nullptr;
	//有右子树
	if (pNode->right) {
		next = pNode->right;
		while (next->left){
			next = next->left;
		}
	}
	//没有右子树，往上找
	else {
		next = pNode->next;
		while (next){
			if (next->left == pNode) {
				return next;
			}else{
				pNode = next;
				next = next->next;
			}
		}
	}
	return next;

}