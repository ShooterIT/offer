/*
*
* 面试题补6：对称的二叉树
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
		if ((a && !b) || (!a&&b)) {
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
/*
	bool isSymmetrical(TreeNode* pRoot)
    {
    	if(!pRoot) return true;
        return isSymmetrical_run(pRoot->left,pRoot->right);

    }
*/
bool isSymmetrical_run(TreeNode *left, TreeNode *right)
{
	if (!left && !right) {
		return true;
	}
	if (left && right) {
		return (left->val == right->val) && isSymmetrical_run(left->left, right->right) &&
			isSymmetrical_run(left->right, right->left);
	}
	return false;
}
