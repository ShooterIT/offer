/*
*
* 面试题27：二叉搜索树与双向链表
*
*/

#include <stack>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(nullptr), right(nullptr) {
	}
};

TreeNode* sub_convert(TreeNode* pRootOfTree , int dir)
{
	if (pRootOfTree == nullptr) {
		return nullptr;
	}

	TreeNode *left = sub_convert(pRootOfTree->left,0);
	if (left) {
		left->right = pRootOfTree;
	}
	pRootOfTree->left = left;
	TreeNode *right = sub_convert(pRootOfTree->right,1);
	if (right) {
		right->left = pRootOfTree;
	}
	pRootOfTree->right = right;

	if (dir == 0) {
		while (pRootOfTree->right != nullptr) {
			pRootOfTree = pRootOfTree->right;
		}
	}else if(dir == 1){
		while (pRootOfTree->left != nullptr) {
			pRootOfTree = pRootOfTree->left;
		}
	}
	return pRootOfTree;
}

TreeNode* Convert(TreeNode* pRootOfTree)
{
	
	if (pRootOfTree == nullptr) {
		return nullptr;
	}
	return sub_convert(pRootOfTree,1);
}
