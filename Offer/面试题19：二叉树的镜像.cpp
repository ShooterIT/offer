/*
*
* 面试题19：二叉树的镜像
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
	TreeNode *tmp = pRoot->left;
	pRoot->left = pRoot->right;
	pRoot->right = tmp;
	Mirror(pRoot->left);
	Mirror(pRoot->right);
}

void Mirror_not_recursive(TreeNode *pRoot)
{
	if (pRoot == nullptr) {
		return;
	}
	stack<TreeNode*> st;
	st.push(pRoot);
	while (!st.empty()){
		TreeNode *node = st.top(); st.pop();
		if (node != nullptr) {
			TreeNode *tmp = node->left;
			node->left = node->right;
			node->right = tmp;
			st.push(node->left);
			st.push(node->right);
		}
	}
}