/*
*
* 面试题18：树的子结构
*
*/

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(nullptr), right(nullptr) {}
};

bool tree1_has_tree2(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (pRoot2 == nullptr) {
		return true;
	}
	if (pRoot1 == nullptr) {
		return false;
	}
	if (pRoot1->val != pRoot2->val) {
		return false;
	}

	return  tree1_has_tree2(pRoot1->left, pRoot2->left)
		&& tree1_has_tree2(pRoot1->right, pRoot2->right);
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	bool result = false;

	if (pRoot1 != nullptr && pRoot2 != nullptr) {
		if (pRoot1->val == pRoot2->val) {
			result = tree1_has_tree2(pRoot1, pRoot2);
		}
		if (!result) {
			result = HasSubtree(pRoot1->left, pRoot2);
		}
		if (!result) {
			result = HasSubtree(pRoot1->right, pRoot2);
		}
	}

	return result;
}