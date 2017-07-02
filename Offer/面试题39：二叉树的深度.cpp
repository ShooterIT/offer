/*
*
* 面试题39：二叉树的深度
* 输入一棵二叉树，求该树的深度。
* 从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
*
*/

#include <algorithm>
#include <cmath>

using std::max;
using std::abs;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(nullptr), right(nullptr) {
	}
}; 

//树的深度
int TreeDepth(TreeNode* pRoot)
{
	//左右子树中较大的+1，即为此层深度
	return pRoot==nullptr ? 0 : max(TreeDepth(pRoot->left), TreeDepth(pRoot->right)) + 1;
}

/* 判断是否是平衡二叉树 */
//是否是平衡二叉树
bool isBalanced(TreeNode *root, int &depth)
{
	if (!root) { 
		depth = 0;
		return true; 
	}
	int left = 0, right = 0;
	//后序遍历，计算左右子树是不是平衡二叉树
	if (isBalanced(root->left, left) &&
		isBalanced(root->right, right)) {
		//计算左右子树的差
		int diff = abs(left - right);
		if(diff <= 1){
			depth = max(left, right) + 1;
			return true;
		}
	}
	return false;
}

bool IsBalanced_Solution(TreeNode* pRoot) 
{
	int depth;
	return isBalanced(pRoot, depth);
}
