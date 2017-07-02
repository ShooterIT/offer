/*
*
* 面试题补9：二叉搜索树的第k个结点
* 给定一颗二叉搜索树，请找出其中的第k大的结点。
* 例如， 5 / \ 3 7 /\ /\ 2 4 6 8 中，按结点数值大小顺序第三个结点的值为4。
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
		//中序遍历
		while (cur) {
			st.push(cur);
			cur = cur->left;
			
		}
		cur = st.top(); st.pop();
		//第i个遍历到的即为第i大的节点
		if (++ith == k) {
			return cur;
		}
		cur = cur->right;
	}
	return nullptr;
}

