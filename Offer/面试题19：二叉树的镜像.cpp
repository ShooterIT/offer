/*
*
* 面试题19：二叉树的镜像
* 操作给定的二叉树，将其变换为源二叉树的镜像
*
*/

#include <stack>

using std::stack;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(nullptr), right(nullptr) {}
};

void Mirror(TreeNode *pRoot) 
{
	if (pRoot == nullptr) {
		return;
	}
	//交换子树
	TreeNode *tmp = pRoot->left;
	pRoot->left = pRoot->right;
	pRoot->right = tmp;
	//递归的交换左右子树
	Mirror(pRoot->left);
	Mirror(pRoot->right);
}

void Mirror_not_recursive(TreeNode *pRoot)
{
	if (pRoot == nullptr) {
		return;
	}
	stack<TreeNode*> st;
	st.push(pRoot); //根节点
	while (!st.empty()){
		TreeNode *node = st.top(); st.pop();
		if (node != nullptr) {
			//交换左右子树
			TreeNode *tmp = node->left;
			node->left = node->right;
			node->right = tmp;
			//左右子树压栈
			st.push(node->left);
			st.push(node->right);
		}
	}
}