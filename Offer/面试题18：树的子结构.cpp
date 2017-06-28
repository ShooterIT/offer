/*
*
* 面试题18：树的子结构
* 输入两棵二叉树A，B，判断B是不是A的子结构。
* （ps：我们约定空树不是任意一个树的子结构）
*
*/

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(nullptr), right(nullptr) {}
};

bool HasSubtreecore(TreeNode* pRoot1, TreeNode* pRoot2)
{
	//pRoot2比较完了，则正确
	if (!pRoot2) {
		return true;
	}
	//pRoot2没有比较完，而pRoot1比较完了，错误
	if (!pRoot1) {
		return false;
	}
	//比较根节点
	if (pRoot1->val != pRoot2->val) {
		return false;
	}
	//递归的比较左右子树
	return HasSubtreecore(pRoot1->left, pRoot2->left) &&
		HasSubtreecore(pRoot1->right, pRoot2->right);
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	bool result = false;
	//先序遍历，根左右
	if (pRoot1 && pRoot2) { //非空才比较
							//先判断根
		result = HasSubtreecore(pRoot1, pRoot2);
		//如果根不满足，判读左子树
		if (!result) {
			result = HasSubtree(pRoot1->left, pRoot2);
		}
		//如果左子树不满足，判读右子树
		if (!result) {
			result = HasSubtree(pRoot1->right, pRoot2);
		}
	}
	return result;
}
