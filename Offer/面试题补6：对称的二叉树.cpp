/*
*
* 面试题补6：对称的二叉树
* 请实现一个函数，用来判断一颗二叉树是不是对称的。
* 注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
*
*/

#include <stack>

using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(nullptr), right(nullptr) {
	}
};

bool isSymmetrical(TreeNode* pRoot)
{
	if (!pRoot) {
		return true;
	}
	stack<TreeNode*> st;
	st.push(pRoot->left);
	st.push(pRoot->right);
	while (!st.empty()){
		TreeNode *a = st.top(); st.pop();
		TreeNode *b = st.top(); st.pop();
		if ((a && !b) || (!a && b)) {
			return false;
		}
		if (a && b && (a->val != b->val)) {
			return false;
		}
		if (a && b) {
			st.push(a->left); st.push(b->right);
			st.push(a->right); st.push(b->left);
		}
	}
	return true;
}

//递归版本
bool isSymmetrical(TreeNode* pRoot)
{
    if(!pRoot) return true;
        return isSymmetrical_run(pRoot->left,pRoot->right);

}

bool isSymmetrical_run(TreeNode *left, TreeNode *right)
{
	//均为空，则比较结束，都相当
	if (!left && !right) {
		return true;
	}
	//两个均不为空
	if (left && right) {
		//先比较值，再比较各自的左右子树是否相等
		return (left->val == right->val) && isSymmetrical_run(left->left, right->right) &&
			isSymmetrical_run(left->right, right->left);
	}
	//其中一个为空，另一个不为空
	return false;
}
