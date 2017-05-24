/*
*
* 面试题补9：二叉搜索树的第k个结点
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

TreeNode* KthNode(TreeNode* pRoot, int k)
{
	if (!pRoot || k <= 0) {
		return nullptr;
	}
	int ith = 0;
	stack<TreeNode*> st;
	TreeNode *cur = pRoot;
	while (cur || !st.empty()){
		while (cur) {
			st.push(cur);
			cur = cur->left;
			
		}
		cur = st.top(); st.pop();
		if (++ith == k) {
			return cur;
		}
		cur = cur->right;
	}
	return nullptr;
}

